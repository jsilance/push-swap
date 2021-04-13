/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:23:59 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/13 03:12:54 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"
#include "get_next_line.h"

#include "debug_utils.h" // TOUT DOUX RIMAUVE BYFOURE PEUCHE


# define D_STACK(name) _BR(0); _print_stack(name, #name );

static void    _print_stack(t_list *stack, const char *name)
{
	size_t	i;
	size_t	size;

	size = ft_lstsize(stack);
	printf("\n=== =START= STACK \"%s\" [%p] === > len %ld <\n", name, stack, size);
	i = 0;
	while (stack)
	{
		printf(
			"[%04ld] NODE [%14p] V data V\n"
			"       |--->[%14p] > %4d < \n"
		, i++, stack, stack->next, stack->content);
		stack = stack->next;
	}
	printf("=== =END= > len %ld <\n", size);
}


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

static void	free_exit(t_table_v *var)
{
	if (var->buf)
		free(var->buf);
	if (var->a)
		ft_lstclear(&var->a);
	if (var->b)
		ft_lstclear(&var->b);
}

static int	verif_stack(t_table_v *var, int mod)
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
			else if (mod && ptr->content < ptr1->content)
				return (1);
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
	return (0);
}

static int print_ret(char *str, int ret)
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

int	main(int argc, char **argv)
{
	t_table_v	var;

	var = (t_table_v){0, 1, NULL, NULL, NULL};
	if (argc == 2)
	{	
		if (str_to_lst(&var, argv[1]))
			return (print_ret("Error\n", 1));
	}
	else
		if (tab_to_lst(&var, argv))
			return (print_ret("Error\n", 1));
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
		if (!verif_stack(&var, 1) && !var.b)
		{
			free_exit(&var);
			return (print_ret("OK\n", 0));
		}
		var.ret = get_next_line(0, &var.buf);
		if (var.ret < 0)
			break ;
		executor(&var.a, &var.b, parser_ins(var.buf));
		free(var.buf);
		var.buf = NULL;
		ft_putstruct(var.a, var.b);
	}
	free_exit(&var);
	return (print_ret("KO\n", 1));
}
