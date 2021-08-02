/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:04:44 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 15:48:18 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	print_push(int ins)
{
	if (ins == I_PA)
		write(1, "pa\n", 3);
	else if (ins == I_PB)
		write(1, "pb\n", 3);
}

void	i_push(t_list **lst, int content, int ins)
{
	t_list	*first;

	first = malloc(sizeof(t_list));
	if (!first)
	{
		ft_lstclear(lst);
		return ;
	}
	print_push(ins);
	if (*lst == NULL)
	{
		*lst = first;
		(*lst)->content = content;
		(*lst)->prev = 0;
		(*lst)->next = 0;
		return ;
	}
	first->prev = 0;
	first->next = *lst;
	first->content = content;
	(*lst)->prev = first;
	*lst = first;
}

void	i_pop(t_list **lst, int content)
{
	t_list	*old;
	t_list	*first;

	if (!*lst)
		return ;
	old = *lst;
	first = *lst;
	while (old && old->content != content)
		old = old->next;
	if (old->next)
		old->next->prev = old->prev;
	if (old->prev)
		old->prev->next = old->next;
	*lst = first;
	if (old == first)
		*lst = old->next;
	free(old);
}
