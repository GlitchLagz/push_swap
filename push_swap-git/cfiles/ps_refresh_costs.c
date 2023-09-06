/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:46:17 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/06 19:06:18 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

// calculates steps for an element to be rotated to the top of its stack

int	cal_steps(t_list **S, int index_m)
{
	if (index_m <= ft_mid_index(S))
		return (index_m);
	else
		return (ft_lstsize(*S) - index_m);
}

// gets the cost to rotate A and B to the top for a given
// number position, this saves moves as you can perform rr
// and rrr which rotates both stacks up or down in one move
// instead of 2 seperate moves.
void	top_rotate_c(t_list **A, t_list **B, t_list *tmp)
{
	int	cost_a;
	int	cost_b;
	int	cost_max;

	cost_a = cal_steps(A, tmp->cur_tar_pos);
	cost_max = cost_a;
	cost_b = cal_steps(B, tmp->pos);
	if (cost_b > cost_max)
		cost_max = cost_b;
	tmp->cost = cost_max;
	if ((tmp->pos <= ft_mid_index(B))
		&& tmp->cur_tar_pos <= ft_mid_index(A))
		tmp->format = 'U';
	else if ((tmp->pos > ft_mid_index(B))
		&& tmp->cur_tar_pos > ft_mid_index(A))
		tmp->format = 'D';
	else
		standard_cost_set(A, B, tmp);
}

// sets the cost for a given node in B that is in 
// a less than ideal condition, a last resort if
// top roatate c function cant set the format to
// up or down.
void	standard_cost_set(t_list **A, t_list **B, t_list *tmp)
{
	int	cost_a;
	int	cost_b;

	cost_a = cal_steps(A, tmp->cur_tar_pos);
	cost_b = cal_steps(B, tmp->pos);
	tmp->cost = cost_a + cost_b;
	tmp->format = 'S';
}

// refresh costs of moving an element to its current
// target position in stack A.
void	refresh_costs(t_list **A, t_list **B)
{
	t_list	*tmp;

	tmp = *B;
	refresh_targets(A, B);
	while (tmp != NULL)
	{
		if ((tmp->pos <= ft_mid_index(B))
			&& tmp->cur_tar_pos <= ft_mid_index(A))
			top_rotate_c(A, B, tmp);
		else if ((tmp->pos > ft_mid_index(B))
			&& tmp->cur_tar_pos > ft_mid_index(A))
			top_rotate_c(A, B, tmp);
		else
			standard_cost_set(A, B, tmp);
		tmp = tmp->nxt;
	}
}
