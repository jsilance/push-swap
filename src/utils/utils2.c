/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 21:03:27 by jsilance          #+#    #+#             */
/*   Updated: 2021/10/20 19:50:52 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_exit(t_table_v *var)
{
	if (var->a)
		ft_lstclear(&var->a);
	if (var->b)
		ft_lstclear(&var->b);
}

int	verif_stack(t_list *lst, int mod)
{
	t_list	*ptr;
	t_list	*ptr1;

	ptr = lst;
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

int	arg_lst(int c, int ac, char **ag, t_table_v *var)
{
	int		i;
	int		j;
	int		value;

	i = 0;
	while (++i <= c)
	{
		if (pre_test(ag[i]) == -1)
			free_exit(var);
		value = ft_satoi(ag[i], var->a);
		ft_lstnew(&var->a, value);
		j = i + 1;
		while (j < ac)
		{
			if (value == ft_satoi(ag[j], var->a))
				return (0);
			j++;
		}
	}
	return (1);
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
