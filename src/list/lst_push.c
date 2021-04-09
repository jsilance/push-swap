/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:04:44 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 03:21:35 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	lst_push(t_list **alst, t_list **blst, int param)
{
// DE(alst);
// DE(*alst);
	if (!alst || !*alst)
	{
// BR;
		return ;
	}
	else if (param == I_PA)
		lst_move(alst, blst);
	else if (param == I_PB)
		lst_move(blst, alst);
}