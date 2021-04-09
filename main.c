/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:23:59 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 06:35:49 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"
#include "get_next_line.h"

#include <stdio.h>

#define	PS(stack) _print_stack(stack, #stack);

static void	_print_stack(t_list *stack, const char *name)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = ft_lstsize(stack);
	printf("\n=== =START= STACK \"%s\" [%p] === > len %ld <\n", name, stack, size);
	i = 0;
	while (stack)
	{
		str = (char*)stack->content;
		printf(
			"[%04ld] NODE [%14p] V data V\n"
			"       |--->[%14p] > \"%4s\" < \n"
		, i++, stack, stack->next, str);
		stack = stack->next;
	}
	printf("=== =END= > len %ld <\n", size);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		ret;
	char	*buf;

	a = NULL;
	b = NULL;
	for (int i = 0; i < argc - 1; i++)
		ft_lstadd_back(&a, ft_lstnew(argv[i + 1]));
	write(1, "\nInit a and b:\n", 15);
	ft_putstruct(a, b);
	while ((ret = get_next_line(0, &buf)) > 0)
	{
		if (!ft_strcmp(buf, "sa"))
			lst_swap(&a);
		else if (!ft_strcmp(buf, "sb"))
			lst_swap(&b);
		else if (!ft_strcmp(buf, "ss"))
		{
			lst_swap(&a);
			lst_swap(&b);
		}
		else if (!ft_strcmp(buf, "pa"))
			lst_push(&a, &b, I_PA);
		else if (!ft_strcmp(buf, "pb"))
			lst_push(&a, &b, I_PB);
		free(buf);
		ft_putstruct(a, b);
	}
	if (buf)
		free(buf);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (0);
}
