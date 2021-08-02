/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 23:48:45 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 19:18:59 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

int	get_len(int len)
{
	if (len % 2)
		len = len / 2 + 1;
	else
		len = len / 2;
	return (len);
}

int	n_sorted(t_list *lst, int mid, int len)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content
			|| (lst->content < mid && len != 3))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	mid_pivot(t_list *ptr, int len)
{
	int		mid;
	t_list	*tmp;
	t_list	*first_nb;

	tmp = lst_dup(ptr);
	if (!tmp)
		return (0);
	first_nb = tmp;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
		{
			i_swap(tmp, -1);
			tmp = first_nb;
		}
		else
			tmp = tmp->next;
	}
	tmp = first_nb;
	len = get_len(len);
	while (--len)
		tmp = tmp->next;
	mid = tmp->content;
	ft_lstclear(&tmp);
	return (mid);
}

int	descend(t_list *lst)
{
	while (lst->prev)
		lst = lst->prev;
	while (lst && lst->next)
	{
		if (lst->content < lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	get_min(t_list *lst)
{
	int	min;

	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}
