/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:33:34 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/06 19:06:15 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

// finds the node that needs the least amount
// of moves to be lined up with its correc pos
// in A.
t_list	*cheapest_node(t_list **B)
{
	t_list	*res;
	t_list	*tmp_b;
	int		min_cost;

	res = *B;
	tmp_b = *B;
	min_cost = tmp_b->cost;
	while (tmp_b != NULL)
	{
		if (tmp_b->cost < min_cost)
		{
			res = tmp_b;
			min_cost = res->cost;
		}
		tmp_b = tmp_b->nxt;
	}
	return (res);
}

// same as rrr_move both but the other direection.
static void	rr_move_both(t_list **A, t_list **B, t_list *c_tmp, int *step_c)
{
	int	min;
	int	a_diff;
	int	b_diff;

	a_diff = c_tmp->cur_tar_pos;
	b_diff = c_tmp->pos;
	min = a_diff;
	if (b_diff < min)
	{
		rr_stacks(A, B, b_diff, step_c);
		a_diff -= b_diff;
		while_ra(A, a_diff, step_c);
	}
	else
	{
		rr_stacks(A, B, a_diff, step_c);
		b_diff -= a_diff;
		while_rb(B, b_diff, step_c);
	}
}

// rrr moves bottom of the list to the top and shifts everything down,
// is a move saver function.
static void	rrr_move_both(t_list **A, t_list **B, t_list *c_tmp, int *step_c)
{
	int	min;
	int	a_diff;
	int	b_diff;

	a_diff = ft_lstsize(*A) - c_tmp->cur_tar_pos;
	b_diff = ft_lstsize(*B) - c_tmp->pos;
	min = a_diff;
	if (b_diff < min)
	{
		rrr_stacks(A, B, b_diff, step_c);
		a_diff -= b_diff;
		while_rra(A, a_diff, step_c);
	}
	else
	{
		rrr_stacks(A, B, a_diff, step_c);
		b_diff -= a_diff;
		while_rrb(B, b_diff, step_c);
	}
}

// standard move, desired element is in a given half of their
// stack and our selected B node is in the opposite half of B.
void	standard_move(t_list **A, t_list **B, t_list *c_tmp, int *step_c)
{
	int	ctp_tmp;
	int	tmp_diff;

	ctp_tmp = c_tmp->cur_tar_pos;
	tmp_diff = ft_lstsize(*A) - c_tmp->cur_tar_pos;
	if (c_tmp->pos <= ft_mid_index(B))
		while_rb(B, c_tmp->pos, step_c);
	else
		while_rrb(B, (ft_lstsize(*B) - c_tmp->pos), step_c);
	if (ctp_tmp <= ft_mid_index(A))
		while_ra(A, ctp_tmp, step_c);
	else
		while_rra(A, tmp_diff, step_c);
}

// Function to execute cheapest operation by getting the
// cheapest node, cost has been calc-ed in refresh_costs().
void	cheapest_move(t_list **A, t_list **B, int *step_c)
{
	t_list	*c_tmp;

	c_tmp = cheapest_node(B);
	if (!c_tmp)
		ft_printf("c_node err\n");
	else if (c_tmp->format == 'U')
		rr_move_both(A, B, c_tmp, step_c);
	else if (c_tmp->format == 'D')
		rrr_move_both(A, B, c_tmp, step_c);
	else if (c_tmp->format == 'S')
		standard_move(A, B, c_tmp, step_c);
	else
	{
		ft_printf("FORMAT NOT SPECIFIED\n");
		exit(1);
	}
	c_tmp = NULL;
	*step_c += pa(A, B);
}
