/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:24:05 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/01 17:09:56 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

t_list	*ft_lstnew_and_pos(int nbr, int index)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->nb = nbr;
	tmp->pos = index;
	tmp->pre = NULL;
	tmp->nxt = NULL;
	return (tmp);
}

int	ra(t_list **stack_a)
{
	t_list	*temp;
	long	first_content;
	int		first_cur_target;
	int		i;

	if (ft_lstsize(*stack_a) <= 0)
		return (0);
	first_content = (*stack_a)->nb;
	first_cur_target = (*stack_a)->cur_tar_pos;
	temp = *stack_a;
	i = 0;
	while (i < ((ft_lstsize(*stack_a)) - 1) && temp->nxt)
	{
		temp->nb = temp->nxt->nb;
		temp->cur_tar_pos = temp->nxt->cur_tar_pos;
		temp = temp->nxt;
	}
	temp = ft_lstlast(*stack_a);
	temp->nb = first_content;
	temp->cur_tar_pos = first_cur_target;
	ft_printf("ra\n");
	return (1);
}

int	r(t_list **stack_a)
{
	t_list	*temp;
	long	first_content;
	int		first_cur_target;
	int		i;

	if (ft_lstsize(*stack_a) <= 0)
		return (0);
	first_content = (*stack_a)->nb;
	first_cur_target = (*stack_a)->cur_tar_pos;
	temp = *stack_a;
	i = 0;
	while (i < ((ft_lstsize(*stack_a)) - 1) && temp->nxt)
	{
		temp->nb = temp->nxt->nb;
		temp->cur_tar_pos = temp->nxt->cur_tar_pos;
		temp = temp->nxt;
	}
	temp = ft_lstlast(*stack_a);
	temp->nb = first_content;
	temp->cur_tar_pos = first_cur_target;
	return (1);
}

int	rb(t_list **stack_b)
{
	t_list	*temp;
	long	first_content;
	int		first_cur_target;
	int		i;

	if (ft_lstsize(*stack_b) <= 0)
		return (0);
	first_content = (*stack_b)->nb;
	first_cur_target = (*stack_b)->cur_tar_pos;
	temp = *stack_b;
	i = 0;
	while (i < ((ft_lstsize(*stack_b)) - 1) && temp->nxt)
	{
		temp->nb = temp->nxt->nb;
		temp->cur_tar_pos = temp->nxt->cur_tar_pos;
		temp = temp->nxt;
	}
	temp = ft_lstlast(*stack_b);
	temp->nb = first_content;
	temp->cur_tar_pos = first_cur_target;
	ft_printf("rb\n");
	return (1);
}

int	rrboth(t_list **A, t_list **B)
{
	int	check_ra;
	int	check_rb;

	check_ra = 0;
	check_rb = 0;
	check_ra += r(A);
	check_rb += r(B);
	if (check_ra + check_rb == 2)
	{
		ft_printf("rr\n");
		return (1);
	}
	else
	{
		if (check_ra)
			rr(A);
		if (check_rb)
			rr(B);
		return (0);
	}
}
