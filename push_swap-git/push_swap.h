/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 06:19:45 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/04 22:31:04 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct s_list
{
	int				nb;
	int				pos;
	int				cur_tar_pos;
	int				cost;
	char			format;
	struct s_list	*pre;
	struct s_list	*nxt;
}				t_list;

char	**ft_split(const char *s, char c);
t_list	*ft_lstnew(int nb);
t_list	*ft_lstlast(t_list *lst);
t_list	*cheapest_node(t_list **B);
t_list	*ft_lstnew_and_pos(int nbr, int index);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstremove_first(t_list **lst);
void	printstack(t_list *s);
void	err_msg(void);
void	err_check(char **argv, int i);
void	flood_a(t_list **A, t_list **B, char **argv, int argc);
void	flood_a2(t_list **A, t_list **B, char **argv, int argc);
void	begin_sort(t_list **A, t_list **B, int *step_c);
void	putnbr(int nb);
void	medium_sort(t_list **A, int *step_c);
void	refresh_costs(t_list **A, t_list **B);
void	refresh_targets(t_list **A, t_list **B);
void	cheapest_move(t_list **A, t_list **B, int *step_c);
void	standard_move(t_list **A, t_list **B, t_list *c_tmp, int *step_c);
void	rrr_stacks(t_list **A, t_list **B, int ro, int *step_c);
void	rr_stacks(t_list **A, t_list **B, int ro, int *step_c);
void	while_rrb(t_list **B, int ro, int *step_c);
void	while_rra(t_list **A, int ro, int *step_c);
void	while_ra(t_list **A, int ro, int *step_c);
void	while_rb(t_list **B, int ro, int *step_c);
void	top_rotate_c(t_list **A, t_list **B, t_list *tmp);
void	standard_cost_set(t_list **A, t_list **B, t_list *tmp);
void	lst_swap(t_list **prev, t_list **tmp);
void	ft_free_err(t_list **A, t_list **B);
int		arglen(char **nbrs);
int		ft_free(t_list *s, t_list *s2);
int		ft_min_index(t_list **S);
int		ft_mid_index(t_list **S);
int		ft_max_index(t_list **S);
int		cal_steps(t_list **S, int index_m);
int		ft_lstsize(t_list *lst);
int		s(t_list *S);
int		sa(t_list *A);
int		sb(t_list *B);
int		ss(t_list *A, t_list *B);
int		pa(t_list **A, t_list **B);
int		pb(t_list **A, t_list **B);
int		r(t_list **S);
int		ra(t_list **A);
int		rb(t_list **B);
int		rr(t_list **S);
int		rra(t_list **A);
int		rrb(t_list **B);
int		rrboth(t_list **A, t_list **B);
int		rrrboth(t_list **A, t_list **B);
int		sort_check(t_list *A);
int		ft_atoi(char *s);
int		main(int argc, char **argv);
long	ft_atoll(char *s);

#endif
