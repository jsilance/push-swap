/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:21:56 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 03:21:55 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	lst_move(t_list **alst, t_list **blst)
{
// DE(alst);
// DE(*alst);
	if (!alst || !*alst)
		return ;
	(*alst)->next = *blst;
	(*blst) = *alst;
	(*alst) = (*alst)->next;
}
