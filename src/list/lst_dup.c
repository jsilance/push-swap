/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:30:37 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/15 18:33:28 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*lst_dup(t_list *lst)
{
	t_list	*ptr;

	ptr = NULL;
	while (lst)
	{
		ft_lstadd_back(&ptr, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (ptr);
}
