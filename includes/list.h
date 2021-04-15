/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:28:57 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/15 19:55:44 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_swap
{
	int				success;
	int				max_ins;
	t_list			*lst;
	t_list			*ins;
	int				fd;
}					t_swap;

typedef struct s_table_v
{
	int		i;
	int		ret;
	t_list	*a;
	t_list	*b;
	char	*buf;
	char	**tab;
	int		ret_val;
}			t_table_v;

enum
{
	I_SA,
	I_SB,
	I_SS,
	I_PA,
	I_PB,
	I_RA,
	I_RB,
	I_RR,
	I_RRA,
	I_RRB,
	I_RRR,
	I_UP,
	I_DO
};

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
int		i_swap(t_list **alst, t_list **blst, int ins);
int		i_rot(t_list **alst, t_list **blst, int ins);
int		i_push(t_list **alst, t_list **blst, int ins);
t_list	*lst_dup(t_list *lst);

#endif
