/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:51:22 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 23:28:11 by jsilance         ###   ########.fr       */
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

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

static void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putstr("2147483648");
			return ;
		}
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}

void	ft_putstruct(t_list *alst, t_list *blst)
{
	ft_putstr("\n");
	while (alst || blst)
	{
		if (alst)
		{
			ft_putnbr(alst->content);
			alst = alst->next;
		}
		else
			ft_putstr(" ");
		ft_putstr(" ");
		if (blst)
		{
			ft_putnbr(blst->content);
			blst = blst->next;
		}
		ft_putstr("\n");
	}
	ft_putstr("_ _\na b\n\n");
}
