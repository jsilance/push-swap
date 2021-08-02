/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 23:53:23 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 16:41:35 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

int	get_max(t_list *lst)
{
	int	min;

	min = lst->content;
	while (lst)
	{
		if (lst->content > min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	to_down(t_list **a, int mid, int len)
{
	int	max;

	max = get_max(*a);
	if (len == 3)
		return ((*a)->next->next->content != max);
	return (*a && (*a)->next && (*a)->content >= mid && ((*a)->content
			> ft_lstlast(*a)->content));
}

int	to_up(t_list **a, int mid, int len)
{
	int	min;

	min = get_min(*a);
	if (len == 3)
		return ((*a)->next->next->content != min);
	return ((*a)->next && (*a)->content >= mid && *a && (*a)->content
		< ft_lstlast(*a)->content);
}

void	sort_three(t_list **a, int mid, int len)
{
	while (n_sorted(*a, mid, len)
		&& to_down(a, mid, len) && (*a)->content >= mid)
		i_rrot(a, I_RRA);
	while (n_sorted(*a, mid, len)
		&& to_up(a, mid, len) && (*a)->content >= mid)
		i_rot(a, I_RA);
}

void	sort_five(t_list **a, int mid, int len)
{
	int	min;

	min = get_min(*a);
	if (distance(*a, min) < (len / 2))
	{
		while (n_sorted(*a, mid, len) && (*a)->content != min)
			i_rot(a, I_RA);
	}
	else
	{
		while (n_sorted(*a, mid, len) && (*a)->content != min)
			i_rrot(a, I_RRA);
	}
}
