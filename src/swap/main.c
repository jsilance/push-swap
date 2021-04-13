/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:13:12 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/14 00:03:08 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"
#include "get_next_line.h"

static int	executor(t_list **alst, t_list **blst, int ins)
{
	static	int	(*ins_table[N_INSTR])(t_list **, t_list **, int) = {
		i_swap, i_swap, i_swap,
		i_push, i_push,
		i_rot, i_rot, i_rot, i_rot, i_rot, i_rot};

	if (ins < 0 || ins > N_INSTR - 1)
		return (1);
	ins_table[ins](alst, blst, ins);
	return (0);
}

static int	print_ret(char *str, int ret)
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

int	*sort_table(t_table_v *var, int range)
{
	t_list	*ptr;
	t_list	*ptr1;
	int		tab[range];

	ptr = var->a;
	range = ft_lstsize(ptr);
	while (ptr)
	{
		ptr1 = ptr->next;
		while (ptr1)
		{
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table_v	var;

	var = (t_table_v){0, 1, NULL, NULL, NULL, arg_lst(&var, argc, argv)};
	if (var.ret_val)
		return (var.ret_val);
	if (!var.a && !var.b)
	{
		free_exit(&var);
		return (0);
	}
	if (verif_stack(&var, 0))
	{
		free_exit(&var);
		return (print_ret("Error\n", 1));
	}
	while (var.ret > 0)
	{
		var.ret = get_next_line(0, &var.buf);
		if (var.ret < 0)
			break ;
		free(var.buf);
		var.buf = NULL;
	}
	free_exit(&var);
	return (0);
}