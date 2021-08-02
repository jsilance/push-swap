/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:37:58 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 19:18:53 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstnew(t_list **lst, int content)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = content;
	new->pos = 0;
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	return ;
}
/*
** Ajouter un nouvel élément
*/
