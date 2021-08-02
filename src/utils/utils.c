/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 05:20:08 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 19:36:12 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	while (s1 && s2 && (s1[count] || s2[count]))
	{
		if ((unsigned char)s1[count] != (unsigned char)s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		count++;
	}
	return (0);
}

int	ft_atoi(char *s)
{
	long	n[2];

	n[0] = 0;
	n[1] = 0;
	if (!s || !*s)
		return (0);
	while ((*s <= 9 && *s >= 13) || *s == 32)
		s++;
	s += ((n[1] = (*s == 45)) || *s == 43);
	while (*s >= 48 && *s <= 57)
	{
		n[0] = (n[0] * 10) + (*s++ - 48);
		if (n[0] < 0)
		{
			if (n[1])
				return (-1);
			return (0);
		}
	}
	if (!n[1])
		return (n[0]);
	return (-n[0]);
}

static int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] && (str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	tab_to_lst(t_table_v *var, char **tab)
{
	int	i;

	i = 1;
	if (!tab || !*tab || !&var->a)
		return (1);
	while (tab[i])
	{
		if (str_is_digit(tab[i]))
			return (1);
		ft_lstnew(&var->a, ft_atoi(tab[i]));
		i++;
	}
	return (0);
}

int	str_to_lst(t_table_v *var, char *str)
{
	int		i;
	t_list	*ptr;

	i = 0;
	if (!str || !*str || str_is_digit(str))
		return (1);
	while (*str)
	{
		ft_lstnew(&var->a, ft_atoi(str));
		while (*str && *str != ' ')
			str++;
		if (*str)
			str++;
	}
	return (0);
}
