/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:46:40 by jsilance          #+#    #+#             */
/*   Updated: 2021/10/20 19:51:45 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pre_test(char *s)
{
	char	*str;

	str = "2147483647";
	if (s[0] == '-')
	{
		s++;
		str = "2147483648";
	}
	if (ft_strlen(s) == 10)
	{
		if (ft_strcmp(str, s) < 0)
			return (-1);
		else
			return (1);
	}
	else if (ft_strlen (s) > 10)
		return (-1);
	return (1);
}
