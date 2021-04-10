/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:04:44 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/10 02:24:02 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	lst_move(t_list **alst, t_list **blst)
{
	t_list	*tmp;

	if (!alst || !*alst)
		return (1);
	tmp = *alst;
	*alst = (*alst)->next;
	tmp->next = *blst;
	*blst = tmp;
	return (0);
}

static int	lst_push(t_list **alst, t_list **blst, int param)
{
	if (param == I_PB)
		return (lst_move(alst, blst));
	else if (param == I_PA)
		return (lst_move(blst, alst));
}

int	i_push(t_list **alst, t_list **blst, int ins)
{
	if (ins == I_PA)
		return (lst_push(alst, blst, I_PA));
	else if (ins == I_PB)
		return (lst_push(alst, blst, I_PB));
}
