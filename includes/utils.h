/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:48:13 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/16 17:03:12 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H
# include "list.h"
# include "unistd.h"

# include <stdio.h>

# define N_INSTR 11

void	ft_putstruct(t_list *alst, t_list *blst);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(char *str);
int		str_to_lst(t_table_v *var, char *str);
int		tab_to_lst(t_table_v *var, char **tab);

void	free_exit(t_table_v *var);
int		verif_stack(t_table_v *var, int mod);
int		arg_lst(t_table_v *var, int argc, char **argv);
size_t	ft_strlen(char *str);
int		print_ret(char *str, int ret);

int		dis_factor_a(t_list *lst);
int		dis_factor_b(t_list *lst);
int		executor(t_list **alst, t_list **blst, int ins);
int		main_swap(t_table_v *var);

#endif
