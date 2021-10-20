/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:28:57 by jsilance          #+#    #+#             */
/*   Updated: 2021/08/10 23:51:23 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_swap
{
	t_list	*lsta;
	t_list	*lstb;
	int		mid;
	int		len;
}					t_swap;

typedef struct s_table_v
{
	int		i;
	int		ret;
	t_list	*a;
	t_list	*b;
	int		ret_val;
}			t_table_v;

enum
{
	S_A,
	S_B
};

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

void	ft_lstnew(t_list **lst, int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
int		i_swap(t_list *lst, int ins);
int		i_rrot(t_list **lst, int ins);
int		i_rot(t_list **lst, int ins);
void	i_push(t_list **lst, int content, int ins);
void	i_pop(t_list **lst, int content);
t_list	*lst_dup(t_list *lst);

#endif
