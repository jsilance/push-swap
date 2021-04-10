/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:19:45 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/10 02:23:56 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static t_list	*lst_get_n(t_list *lst, int n)
{
	if (!lst)
		return (0);
	while (lst && lst->next && --n)
		lst = lst->next;
	return (lst);
}

static int	lst_rot(t_list **lst, int param)
{
	t_list	*tmpa;

	if (!lst || !*lst || !(*lst)->next)
		return (1);
	if (param == I_UP)
	{
		tmpa = *lst;
		*lst = (*lst)->next;
		ft_lstlast(*lst)->next = tmpa;
		tmpa->next = NULL;
	}
	else if (param == I_DO)
	{
		tmpa = ft_lstlast(*lst);
		lst_get_n(*lst, ft_lstsize(*lst) - 1)->next = NULL;
		tmpa->next = *lst;
		*lst = tmpa;
	}
	return (0);
}

int	i_rot(t_list **alst, t_list **blst, int ins)
{
	if (ins == I_RA || ins == I_RR)
		lst_rot(alst, I_UP);
	if (ins == I_RB || ins == I_RR)
		lst_rot(blst, I_UP);
	if (ins == I_RRA || ins == I_RRR)
		lst_rot(alst, I_DO);
	if (ins == I_RRB || ins == I_RRR)
		lst_rot(blst, I_DO);
	return (0);
}
