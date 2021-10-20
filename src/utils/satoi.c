/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   satoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 01:56:11 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/03 02:25:18 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	stack_error(t_list *a)
{
	write(1, "Error\n", 6);
	ft_lstclear(&a);
	exit (0);
}

static void	check_digit(char c, t_list *a)
{
	if (!ft_isdigit(c))
	{
		write(1, "Error\n", 6);
		ft_lstclear(&a);
		exit (0);
	}
}

int	ft_satoi(const char *str, t_list *a)
{
	int						i;
	int						sign;
	unsigned long long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign(str[i++]);
	check_digit(str[i], a);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i++] - '0');
		if (n > (unsigned long long)(1 << 31) - 1 && !((int)n == (1 << 31)
			&& sign < 0))
			stack_error(a);
	}
	if (str[i])
		check_digit(str[i], a);
	return (sign * (int)n);
}
