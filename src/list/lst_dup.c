/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:30:37 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 01:11:34 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*lst_dup(t_list *lst)
{
	t_list	*ptr;

	ptr = NULL;
	while (lst)
	{
		ft_lstnew(&ptr, lst->content);
		lst = lst->next;
	}
	return (ptr);
}
