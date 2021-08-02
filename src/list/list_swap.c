/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:41:31 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 01:27:22 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	i_swap(t_list *lst, int ins)
{
	int	tmp;

	tmp = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp;
	if (ins == I_SA || ins == I_SB || ins == I_SS)
	{
		write(1, "s", 1);
		if (ins == I_SS)
			write(1, "s", 1);
		else if (ins == I_SA)
			write(1, "a", 1);
		else if (ins == I_SB)
			write(1, "b", 1);
		write(1, "\n", 1);
	}
}
