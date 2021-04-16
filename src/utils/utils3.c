/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:35:01 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/16 18:12:07 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	dis_factor_a(t_list *lst)
{
	t_list	*ptr;
	t_list	*ptr1;
	int		factor;

	ptr = lst;
	factor = 0;
	while (ptr)
	{
		ptr1 = ptr->next;
		while (ptr1)
		{
			if (ptr->content > ptr1->content)
				factor++;
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
	return (factor);
}
// {
// 	int		factor;
// 	t_list	*ptr;
// 	t_list	*ptr1;

// 	factor = 0;
// 	ptr = lst;
// 	if (ptr && ptr->next)
// 		ptr1 = ptr->next;
// 	while (ptr && ptr->next)
// 	{
// 		if (ptr->content > ptr1->content)
// 			factor++;
// 		ptr = ptr->next;
// 		ptr1 = ptr1->next;
// 	}
// 	return (factor);
// }

int	dis_factor_b(t_list *lst)
{
	int		factor;
	t_list	*ptr;

	factor = 0;
	ptr = lst;
	while (ptr && ptr->next)
	{
		if (ptr->content < ptr->next->content)
			factor++;
		ptr = ptr->next;
	}
	return (factor);
}

int	executor(t_list **alst, t_list **blst, int ins)
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
