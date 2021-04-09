/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:41:31 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 02:54:59 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	lst_swap(t_list **lst)
{
	t_list	*lst_tmp;

	lst_tmp = NULL;
	if (!lst || !*lst || !(*lst)->next)
		return (1);
	lst_move(&(*lst), &(*lst)->next);
	return (0);
}
