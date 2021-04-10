/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:48:13 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/10 01:15:19 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H
# include "list.h"
# include "unistd.h"

# define N_INSTR 11

void	ft_putstruct(t_list *alst, t_list *blst);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(char *str);

#endif
