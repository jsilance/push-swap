/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 01:04:12 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 17:15:42 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "list.h"

int	distance(t_list *lst, int min)
{
	int	i;

	i = 0;
	while (lst && lst->content != min)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static void	ft_quicksort(t_list *tmp, t_list *first)
{
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
		{
			i_swap(tmp, -1);
			tmp = first;
		}
		else
			tmp = tmp->next;
	}
}

static void	normal_value(t_list **lst, t_list *tmp, int i)
{
	if (lst && *lst && !(*lst)->pos)
	{
		(*lst)->content = i;
		(*lst)->pos = 1;
	}
	else
	{
		if (lst && *lst)
			*lst = (*lst)->next;
		while (lst && *lst && (*lst)->content != tmp->content)
			*lst = (*lst)->next;
		if (lst && *lst)
		{
			(*lst)->content = i;
			(*lst)->pos = 1;
		}
	}
}

void	normalize_lst(t_list **lst)
{
	int		i;
	t_list	*tmp;
	t_list	*first;

	tmp = lst_dup(*lst);
	if (!tmp)
	{
		ft_lstclear(lst);
		exit(0);
	}
	first = tmp;
	i = 0;
	ft_quicksort(tmp, first);
	tmp = first;
	while (tmp)
	{
		while (lst && *lst && (*lst)->content != tmp->content)
			*lst = (*lst)->next;
		normal_value(lst, tmp, i);
		while (lst && *lst && (*lst)->prev)
			*lst = (*lst)->prev;
		i++;
		tmp = tmp->next;
	}
	ft_lstclear(&first);
}

int	to_swap(t_list **a, int mid, int len)
{
	int	max;
	int	min;

	min = get_min(*a);
	max = get_max(*a);
	if (len == 3)
		return (!(((*a)->content == max && (*a)->next->content == min)
				|| ((*a)->content == mid && (*a)->next->content == max)));
	return ((*a)->content >= mid && (*a)->content > (*a)->next->content);
}
