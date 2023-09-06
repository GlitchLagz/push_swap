/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:58:56 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/06 18:57:02 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	sort_check(t_list *A)
{
	t_list	*tmp;

	tmp = A;
	A = A->nxt;
	while (A != NULL)
	{
		if (tmp->nb > A->nb)
			return (0);
		tmp = A;
		A = A->nxt;
	}
	return (1);
}

void	medium_sort(t_list **A, int *step_c)
{
	int	max_index;
	int	min_index;

	max_index = -1;
	min_index = -1;
	if (sort_check(*A))
		return ;
	max_index = ft_max_index(A);
	if (max_index == 1)
		*step_c += rra(A);
	if (max_index == 0)
		*step_c += ra(A);
	min_index = ft_min_index(A);
	if (min_index == 1)
		*step_c += sa(*A);
}

//	COST EVAL SORT:
//	1. Pushes all nbrs from A to B except 3.
//	2. Sorts 3 on A using medium sort.
//	3. Uses Refresh Costs funtion to calculate cost to move
//	an element from B to the correct spot on A
//	4. Uses Cheapest move to execute cheapest operation/move
//	leaves A in order.
//	5. Refresh Target-Cost values in B nodes after executing an
//	opperationeration to update with the current position of A and new nodes.
//	6. Loops steps 3 to 5 until B is empty.
//	7. if A is rotated the wrong way, use rotate A
//	or reverse rotate A to rotate stack A into order.

void	begin_sort(t_list **A, t_list **B, int *step_c)
{
	if (ft_lstsize(*A) == 2)
	{
		sa(*A);
		ft_free(*A, *B);
	}
	while ((ft_lstsize(*A)) > 3)
		*step_c += pb(A, B);
	medium_sort(A, step_c);
	refresh_costs(A, B);
	while (ft_lstsize(*B) > 0)
	{
		cheapest_move(A, B, step_c);
		refresh_costs(A, B);
	}
	if (ft_min_index(A) <= ft_mid_index(A))
		while (ft_min_index(A) != 0)
			*step_c += ra(A);
	else
		while (ft_min_index(A) != 0)
			*step_c += rra(A);
}
