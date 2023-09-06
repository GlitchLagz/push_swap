/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:26:39 by tpawson           #+#    #+#             */
/*   Updated: 2023/08/30 04:52:48 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	sa(t_list *stack_a)
{
	long	temp1;
	long	temp2;

	if ((ft_lstsize(stack_a)) < 2)
		return (0);
	temp1 = stack_a->nb;
	temp2 = stack_a->nxt->nb;
	stack_a->nb = temp2;
	stack_a->nxt->nb = temp1;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_list *stack_b)
{
	long	temp1;
	long	temp2;

	if ((ft_lstsize(stack_b)) < 2)
		return (0);
	temp1 = stack_b->nb;
	temp2 = stack_b->nxt->nb;
	stack_b->nb = temp2;
	stack_b->nxt->nb = temp1;
	ft_printf("sb\n");
	return (1);
}

int	s(t_list *stack_b)
{
	long	temp1;
	long	temp2;

	if ((ft_lstsize(stack_b)) < 2)
		return (0);
	temp1 = stack_b->nb;
	temp2 = stack_b->nxt->nb;
	stack_b->nb = temp2;
	stack_b->nxt->nb = temp1;
	return (1);
}

int	ft_ss(t_list *stack_a, t_list *stack_b)
{
	int	sa_check;
	int	sb_check;

	sa_check = 0;
	sb_check = 0;
	sa_check += s(stack_a);
	sb_check += s(stack_b);
	if (sa_check + sb_check == 2)
	{
		ft_printf("ss\n");
		return (1);
	}
	else
	{
		if (sa_check)
			s(stack_a);
		if (sb_check)
			s(stack_b);
		return (0);
	}
}
