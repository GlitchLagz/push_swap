/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:23:45 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/01 22:02:25 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	pa(t_list **A, t_list **B)
{
	t_list	*tmp;

	if (ft_lstsize(*B) <= 0)
		return (0);
	tmp = ft_lstnew_and_pos((*B)->nb, 0);
	if (*A == NULL)
	{
		ft_lstadd_front(A, tmp);
		*A = tmp;
	}
	else
	{
		tmp->nxt = *A;
		(*A)->pre = tmp;
		*A = tmp;
		tmp = tmp->nxt;
		while (tmp != NULL)
		{
			tmp->pos += 1;
			tmp = tmp->nxt;
		}
	}
	ft_lstremove_first(B);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_list **A, t_list **B)
{
	t_list	*tmp;

	if (ft_lstsize(*A) <= 0)
		return (0);
	tmp = ft_lstnew_and_pos((*A)->nb, 0);
	if (*B == NULL)
	{
		ft_lstadd_front(B, tmp);
		*B = tmp;
	}
	else
	{
		tmp->nxt = *B;
		(*B)->pre = tmp;
		*B = tmp;
		tmp = tmp->nxt;
		while (tmp != NULL)
		{
			tmp->pos += 1;
			tmp = tmp->nxt;
		}
	}
	ft_lstremove_first(A);
	ft_printf("pb\n");
	return (1);
}
