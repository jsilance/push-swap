/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:17:20 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/16 21:39:09 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

#include <fcntl.h>

// static t_swap	*swap_finder(t_swap	*ptr, int ins, int max_ins)
// {
// 	static char	*str_ins[11] = {
// 	"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

// 	if (max_ins <= 0)
// 		return (NULL);
// 	max_ins--;
// 	swap_finder(ptr, I_SA, max_ins);
// 	swap_finder(ptr, I_RA, max_ins);
// 	swap_finder(ptr, I_RRA, max_ins);
// 	if (max_ins <= 0)
// 	{
// 		ptr->success = 0;
// 		return (ptr);
// 	}
// }

static int	compute_exec(t_swap *ptr, int ins)
{
	ptr->dis_factor_old[0] = ptr->dis_factor[0];
	ptr->dis_factor_old[1] = ptr->dis_factor[1];
	executor(&ptr->lsta, &ptr->lstb, ins);
	ptr->dis_factor[0] = dis_factor_a(ptr->lsta);
	ptr->dis_factor[1] = dis_factor_a(ptr->lstb);
	// printf("[%d][%d]\n[%d][%d]\n\n", ptr->dis_factor_old[0], ptr->dis_factor[0], ptr->dis_factor_old[1], ptr->dis_factor[1]);
	return (0);
}

static int	compute_ins(t_swap *ptr, t_table_v *var)
{
	int	i;

	i = 0;
	printf("1[%d]\n", (ptr->lsta || ptr->lstb) && verif_stack(var, 1));
	while ((ptr->lsta || ptr->lstb) && verif_stack(var, 1))
	{
		// printf("*1*[%d][%d]**\n", (ptr->lsta || ptr->lstb), verif_stack(var, 1));
		ft_putstruct(ptr->lsta, ptr->lstb);
		if (ptr->dis_factor[0] || ptr->dis_factor[1])
			compute_exec(ptr, I_SA);
		if (ptr->dis_factor[0] || ptr->dis_factor[1])
			if (ptr->dis_factor_old[0] < ptr->dis_factor[0] || ptr->dis_factor_old[1] < ptr->dis_factor[1])
				executor(&ptr->lsta, &ptr->lstb, I_SA);
		// ft_putstruct(ptr->lsta, ptr->lstb);
		// printf("*2*[%d][%d]**\n", (ptr->lsta || ptr->lstb), verif_stack(var, 1));
		// ft_putstruct(ptr->lsta, ptr->lstb);
		if (ptr->dis_factor[0] || ptr->dis_factor[1])
			compute_exec(ptr, I_RA);
		if (ptr->dis_factor[0] || ptr->dis_factor[1])
			if (ptr->dis_factor_old[0] < ptr->dis_factor[0] || ptr->dis_factor_old[1] < ptr->dis_factor[1])
				executor(&ptr->lsta, &ptr->lstb, I_RRA);
		// printf("*3*[%d][%d]**\n", (ptr->lsta || ptr->lstb), verif_stack(var, 1));
		// ft_putstruct(ptr->lsta, ptr->lstb);
		if (ptr->dis_factor[0] || ptr->dis_factor[1])
			compute_exec(ptr, I_RRA);
		if (ptr->dis_factor[0] || ptr->dis_factor[1])
			if (ptr->dis_factor_old[0] < ptr->dis_factor[0] || ptr->dis_factor_old[1] < ptr->dis_factor[1])
				executor(&ptr->lsta, &ptr->lstb, I_RA);
		// ft_putstruct(ptr->lsta, ptr->lstb);
		// printf("*4*[%d][%d]**\n", (ptr->lsta || ptr->lstb), verif_stack(var, 1));
		var->a = ptr->lsta;
		var->b = ptr->lstb;
	}
		// ft_putstruct(ptr->lsta, ptr->lstb);
}

int	main_swap(t_table_v *var)
{
	t_swap	ptr;

	ptr = (t_swap){0, var->a, var->b, NULL};
	ptr.dis_factor[0] = dis_factor_a(var->a);
	ptr.dis_factor[1] = dis_factor_b(var->b);
	ptr.dis_factor_old[0] = 0;
	ptr.dis_factor_old[1] = 0;
	printf("disA[%d]	disB[%d]\n", ptr.dis_factor[0], ptr.dis_factor[1]);
	compute_ins(&ptr, var);
	printf("disA[%d]	disB[%d]\n", ptr.dis_factor[0], ptr.dis_factor[1]);
	ft_putstruct(ptr.lsta, ptr.lstb);
	// swap_finder(&ptr, I_SA, ft_lstsize(var->a) * 3 / 2 + 1);
}
