/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 04:48:13 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/02 19:18:40 by jsilance         ###   ########.fr       */
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
int		str_to_lst(t_table_v *var, char *str);
int		tab_to_lst(t_table_v *var, char **tab);

void	free_exit(t_table_v *var);
int		verif_stack(t_list *lst, int mod);
int		arg_lst(int c, int ac, char **ag, t_list **a);
size_t	ft_strlen(char *str);
int		print_ret(char *str, int ret);

void	trash_list(t_list **lsta, t_list **lstb);
int		dis_factor_a(t_list *lst);
int		dis_factor_b(t_list *lst);
int		executor(t_list **alst, t_list **blst, int ins);
int		main_swap(t_table_v *var);

int		get_len(int len);
int		n_sorted(t_list *lst, int mid, int len);
int		mid_pivot(t_list *ptr, int len);
int		descend(t_list *lst);
int		get_min(t_list *lst);

int		get_max(t_list *lst);
int		to_down(t_list **a, int mid, int len);
int		to_up(t_list **a, int mid, int len);
void	sort_three(t_list **a, int mid, int len);
void	sort_five(t_list **a, int mid, int len);

int		distance(t_list *lst, int min);
void	normalize_lst(t_list **lst);
int		to_swap(t_list **a, int mid, int len);

#endif
