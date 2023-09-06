/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:24:47 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/01 17:10:36 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	rra(t_list **stack_a)
{
	t_list	*temp;
	int		last_content;
	int		i;
	int		a_len;

	a_len = ft_lstsize(*stack_a);
	if (a_len <= 0)
		return (0);
	last_content = (ft_lstlast(*stack_a))->nb;
	temp = ft_lstlast(*stack_a);
	i = 0;
	while (i < (a_len - 1) && temp->pre)
	{
		temp->nb = temp->pre->nb;
		temp = temp->pre;
	}
	temp = *stack_a;
	temp->nb = last_content;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_list **stack_b)
{
	t_list	*temp;
	int		last_content;
	int		i;
	int		b_len;

	b_len = ft_lstsize(*stack_b);
	if (b_len <= 0)
		return (0);
	last_content = (ft_lstlast(*stack_b))->nb;
	temp = ft_lstlast(*stack_b);
	i = 0;
	while (i < (b_len - 1) && temp->pre)
	{
		temp->nb = temp->pre->nb;
		temp = temp->pre;
	}
	temp = *stack_b;
	temp->nb = last_content;
	ft_printf("rrb\n");
	return (1);
}

int	rr(t_list **stack_b)
{
	t_list	*temp;
	int		last_content;
	int		i;
	int		b_len;

	b_len = ft_lstsize(*stack_b);
	if (b_len <= 0)
		return (0);
	last_content = (ft_lstlast(*stack_b))->nb;
	temp = ft_lstlast(*stack_b);
	i = 0;
	while (i < (b_len - 1) && temp->pre)
	{
		temp->nb = temp->pre->nb;
		temp = temp->pre;
	}
	temp = *stack_b;
	temp->nb = last_content;
	return (1);
}

int	rrrboth(t_list **stack_a, t_list **stack_b)
{
	int	rra_check;
	int	rrb_check;

	rra_check = 0;
	rrb_check = 0;
	rra_check += rr(stack_a);
	rrb_check += rr(stack_b);
	if (rra_check + rrb_check == 2)
	{
		ft_printf("rrr\n");
		return (1);
	}
	else
	{
		if (rra_check)
			r(stack_a);
		if (rrb_check)
			r(stack_b);
		return (0);
	}
}
