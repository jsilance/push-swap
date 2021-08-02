/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:07:35 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/09 00:39:55 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	if (alst && *alst)
		ft_lstlast(*alst)->next = new;
	else if (alst)
		*alst = new;
}
/*
** Ajouter un élément à la fin d'une liste chainée
*/
