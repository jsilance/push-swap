/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:23:59 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/10 02:22:17 by jsilance         ###   ########.fr       */
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

static int	parser_ins(char *str)
{
	int			i;
	static char	*str_ins[N_INSTR] = {
	"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < N_INSTR)
		if (!ft_strcmp(str, str_ins[i++]))
			return (i - 1);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_table_v	var;

	var = (t_table_v){0, 1, NULL, NULL, NULL};
	while (var.i < argc - 1)
		ft_lstadd_back(&var.a, ft_lstnew(ft_atoi(argv[var.i++ + 1])));
	ft_putstruct(var.a, var.b);
	while (var.ret > 0)
	{
		var.ret = get_next_line(0, &var.buf);
		if (var.ret < 0)
			break ;
		executor(&var.a, &var.b, parser_ins(var.buf));
		free(var.buf);
		ft_putstruct(var.a, var.b);
	}
	if (var.buf)
		free(var.buf);
	if (var.a)
		ft_lstclear(&var.a);
	if (var.b)
		ft_lstclear(&var.b);
	return (0);
}
