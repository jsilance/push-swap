/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:37:25 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 02:33:24 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst && ++i)
		lst = lst->next;
	return (i);
}
/*
** Compter le nombre d'éléments d'une chaine
*/
