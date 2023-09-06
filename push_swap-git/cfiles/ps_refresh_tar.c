/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:45:22 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/06 18:51:51 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

// target calculation for any number 
// not at the end of the linked lists
static int	nxt_non_null(t_list **A, t_list *tmp_A, t_list *tmp_B)
{
	if (sort_check(*A))
	{
		if (tmp_B->nb < tmp_A->nb && tmp_A->pos == 0)
		{
			tmp_B->cur_tar_pos = 0;
			return (1);
		}
	}
	if (tmp_B->nb > tmp_A->nb
		&& tmp_B->nb < tmp_A->nxt->nb)
	{
		tmp_B->cur_tar_pos = tmp_A->pos + 1;
		return (1);
	}
	else if (tmp_B->nb > tmp_A->nb
		&& tmp_A->nxt->pos == ft_min_index(A))
	{
		tmp_B->cur_tar_pos = tmp_A->pos + 1;
		return (1);
	}
	return (0);
}

// target calculation for the end of the linked
// list.
static int	nxt_null_case(t_list **A, t_list *tmp_A, t_list *tmp_B)
{
	if (sort_check(*A))
	{
		if (tmp_B->nb < tmp_A->nb)
		{
			tmp_B->cur_tar_pos = 0;
			return (1);
		}
	}
	if (tmp_B->nb < (*A)->nb
		&& tmp_B->nb > tmp_A->nb)
		tmp_B->cur_tar_pos = 0;
	if (tmp_B->nb > tmp_A->nb
		&& sort_check(*A))
		tmp_B->cur_tar_pos = (tmp_A->pos + 1);
	return (0);
}

// target calculation for an odd case
static int	final_check(t_list *tmp_A, t_list *tmp_B, int min_index)
{
	if (tmp_A->pos == min_index && tmp_B->nb < tmp_A->nb)
	{
		tmp_B->cur_tar_pos = tmp_A->pos;
		return (1);
	}
	return (0);
}

//	Function that calls on other functions
//	for each case
static int	check(t_list **A, t_list *tmp_A, t_list *tmp_B, int min_index)
{
	if (tmp_A->nxt != NULL)
	{
		if (nxt_non_null(A, tmp_A, tmp_B))
			return (1);
	}
	else
	{
		if (nxt_null_case(A, tmp_A, tmp_B))
			return (1);
	}
	if (final_check(tmp_A, tmp_B, min_index))
		return (1);
	return (0);
}

// Refresh the nodes in B with their Cur_Tar_Pos
// within A.
void	refresh_targets(t_list **A, t_list **B)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		min_index;

	tmpb = *B;
	min_index = ft_min_index(A);
	while (tmpb != NULL)
	{
		tmpa = *A;
		while (tmpa != NULL)
		{
			if (check(A, tmpa, tmpb, min_index))
				break ;
			tmpa = tmpa->nxt;
		}
		tmpb = tmpb->nxt;
	}
}
