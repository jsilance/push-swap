/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:23:59 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 03:25:00 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
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

	a = NULL;
	for (int i = 0; i < argc - 1; i++)
		ft_lstadd_back(&a, ft_lstnew(argv[i + 1]));
	// PS(a);
	// PS(b);

	t_list	*b;
	b = NULL;

	for (int i = 0; i < argc - 1; i++)
	{
// DE(a);
// DE(&a);
// DE(b);
		lst_push(&a, &b, I_PB);
		// PS(b);
	}
	// ft_lstclear(&a, &free);
	// ft_lstclear(&b, &free);
	return (0);
}
