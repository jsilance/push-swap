/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:17:20 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 19:18:57 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

void	trash_list(t_list **lsta, t_list **lstb)
{
	while (*lstb)
	{
		i_push(lsta, (*lstb)->content, I_PA);
		i_pop(lstb, (*lstb)->content);
	}
}

static void	small_ins(t_list **lsta, t_list **lstb)
{
	if (*lstb && (*lstb)->next && (*lstb)->content
		< (*lstb)->next->content)
		i_swap(*lstb, I_SB);
	else if (*lstb && !descend(*lstb) && (*lstb)->content
		> ft_lstlast(*lstb)->content)
		i_rrot(lstb, I_RRB);
	else if (*lstb && !descend(*lstb) && (*lstb)->content
		< ft_lstlast(*lstb)->content)
		i_rot(lstb, I_RRB);
}

static void	small_sort(t_list **lsta, t_list **lstb, int mid, int l)
{
	while (lsta && *lsta && n_sorted(*lsta, mid, l))
	{
		if (lsta && *lsta && (*lsta)->next && to_swap(lsta, mid, l))
			i_swap(*lsta, I_SA);
		while (l != 3 && lsta && *lsta && n_sorted(*lsta, mid, l)
			&& (*lsta)->content < mid)
		{
			i_push(lstb, (*lsta)->content, I_PB);
			i_pop(lsta, (*lsta)->content);
			small_ins(lsta, lstb);
		}
		if (ft_lstsize(*lsta) != 3)
			sort_five(lsta, mid, l);
		else
			sort_three(lsta, mid, l);
	}
	trash_list(lsta, lstb);
}

static void	large_sort(t_list **alst, t_list **blst)
{
	int	lst;
	int	i;

	i = 0;
	normalize_lst(alst);
	while (alst && *alst && verif_stack(*alst, 1))
	{
		lst = ft_lstsize(*alst);
		while (alst && *alst && lst--)
		{
			if ((((*alst)->content >> i) & 1))
				i_rot(alst, I_RA);
			else
			{
				i_push(blst, (*alst)->content, I_PB);
				i_pop(alst, (*alst)->content);
			}
		}
		trash_list(alst, blst);
		i++;
	}
}

int	main_swap(t_table_v *var)
{
	t_swap	ptr;

	if (!var->b && !verif_stack(var->a, 1))
		return (1);
	ptr = (t_swap){var->a, var->b};
	ptr.len = ft_lstsize(ptr.lsta);
	ptr.mid = mid_pivot(ptr.lsta, ptr.len);
	if (ptr.len <= 5)
		small_sort(&ptr.lsta, &ptr.lstb, ptr.mid, ptr.len);
	else
		large_sort(&ptr.lsta, &ptr.lstb);
}
