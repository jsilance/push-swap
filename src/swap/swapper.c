/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:17:20 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/16 00:53:29 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

#include <fcntl.h>

t_swap	*swap_dup(t_swap *ptr)
{
	t_swap	*var;

	var = (t_swap *){ptr->success, ptr->max_ins, };
}

static t_swap	*swap_finder(t_swap	*ptr, int ins)
{
	static char	*str_ins[11] = {
	"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	ptr->max_ins--;
	write(ptr->fd, str_ins[ins], ft_strlen(str_ins[ins]));
	swap_finder(ptr, I_SA);
	swap_finder(ptr, I_RA);
	swap_finder(ptr, I_RRA);
	write(ptr->fd, "\n", 1);
	if (ptr->max_ins <= 0)
	{
		ptr->success = 0;
		return (ptr);
	}
}
/*t_swap	*swap_finder(t_swap	*ptr, int ins)
{
	ptr->max_ins--;
	ft_lstadd_front(ptr->ins, ft_lstnew(ins));
	if (ptr->max_ins <= 0)
	{
		ptr->success = 0;
		return (ptr);
	}
	ptr = swap_finder(ptr, I_SA);
	if (!ptr)
		return (NULL);
	return (ptr);
}*/

int	main_swap(t_table_v *var)
{
	t_swap	*ptr;

	ptr = (t_swap *){0, ft_lstsize(var->a) * 3 / 2, var->a, NULL, open("sim.txt", O_RDONLY || O_CREAT)};
	ptr = swap_finder(ptr, I_SA);
}
