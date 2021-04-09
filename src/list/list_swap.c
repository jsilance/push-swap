/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:41:31 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 06:24:12 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	lst_swap(t_list **lst)
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
