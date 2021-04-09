/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:21:56 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 04:41:20 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	lst_move(t_list **alst, t_list **blst)
{
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	*alst = (*alst)->next;
	tmp->next = *blst;
	*blst = tmp;
}
