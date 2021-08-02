/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:19:45 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 16:49:01 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	lst_rrot(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!*lst)
		return ;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	last = *lst;
	if (!(*lst)->prev)
		return ;
	last->prev->next = 0;
	first = (*lst)->prev;
	*lst = last;
	while (first && first->prev)
		first = first->prev;
	first->prev = last;
	last->next = first;
	last->prev = 0;
}

int	i_rrot(t_list **lst, int ins)
{
	lst_rrot(lst);
	if (ins == I_RRA)
		write(1, "rra\n", 4);
	if (ins == I_RRB)
		write(1, "rrb\n", 4);
	if (ins == I_RRR)
		write(1, "rrr\n", 4);
	return (0);
}

static void	lst_rot(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!lst)
		return ;
	while (lst && (*lst)->prev)
		*lst = (*lst)->prev;
	last = *lst;
	if (!(*lst)->next)
		return ;
	first = (*lst)->next;
	*lst = first;
	first->prev = 0;
	while (first && first->next)
		first = first->next;
	first->next = last;
	last->next = 0;
	last->prev = first;
}

int	i_rot(t_list **lst, int ins)
{
	lst_rot(lst);
	if (ins == I_RA)
		write(1, "ra\n", 3);
	if (ins == I_RB)
		write(1, "rb\n", 3);
	if (ins == I_RR)
		write(1, "rr\n", 3);
	return (0);
}
