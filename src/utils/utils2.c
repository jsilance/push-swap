/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 21:03:27 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/15 21:57:56 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_exit(t_table_v *var)
{
	if (var->buf)
		free(var->buf);
	if (var->a)
		ft_lstclear(&var->a);
	if (var->b)
		ft_lstclear(&var->b);
}

int	verif_stack(t_table_v *var, int mod)
{
	t_list	*ptr;
	t_list	*ptr1;

	ptr = var->a;
	while (ptr)
	{
		ptr1 = ptr->next;
		while (ptr1)
		{
			if (!mod && ptr->content == ptr1->content)
				return (1);
			else if (mod && ptr->content > ptr1->content)
				return (1);
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
	return (0);
}

int	arg_lst(t_table_v *var, int argc, char **argv)
{
	if (argc == 2)
	{	
		if (str_to_lst(var, argv[1]))
			return (print_ret("Error\n", 1));
	}
	else
		if (tab_to_lst(var, argv))
			return (print_ret("Error\n", 1));
	return (0);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	print_ret(char *str, int ret)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 3)
		write(2, str, i);
	else
		write(1, str, i);
	return (ret);
}
