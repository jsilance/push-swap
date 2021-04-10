/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:41:31 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/10 01:59:58 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	lst_swap(t_list **lst)
{
	t_list	*tmpa;
	t_list	*tmpb;
	t_list	*tmpc;

	if (!lst || !*lst || !(*lst)->next)
		return (1);
	tmpa = *lst;
	tmpb = (*lst)->next;
	tmpc = tmpb->next;
	tmpa->next = tmpc;
	tmpb->next = tmpa;
	*lst = tmpb;
	return (0);
}

int	i_swap(t_list **alst, t_list **blst, int ins)
{
	if (ins == I_SA || ins == I_SS)
		lst_swap(alst);
	if (ins == I_SB || ins == I_SS)
		lst_swap(blst);
}
