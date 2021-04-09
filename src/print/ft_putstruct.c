/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:51:22 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 05:36:25 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && *str++)
		i++;
	return (i);
}

static void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putstruct(t_list *alst, t_list *blst)
{
	ft_putstr("\n");
	while (alst || blst)
	{
		if (alst)
		{
			write(1, alst->content, 1);
			alst = alst->next;
		}
		else
			ft_putstr(" ");
		ft_putstr(" ");
		if (blst)
		{
			write(1, blst->content, 1);
			blst = blst->next;
		}
		ft_putstr("\n");
	}
	ft_putstr("_ _\na b\n\n");
}
