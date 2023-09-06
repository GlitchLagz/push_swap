/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:15:56 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/01 18:05:16 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	while_rra(t_list **A, int ro, int *step_c)
{
	int	i;

	i = -1;
	while (++i < ro)
		*step_c += rra(A);
}

void	while_rrb(t_list **B, int ro, int *step_c)
{
	int	i;

	i = -1;
	while (++i < ro)
		*step_c += rrb(B);
}

void	rrr_stacks(t_list **A, t_list **B, int ro, int *step_c)
{
	int	i;

	i = -1;
	while (++i < ro)
		*step_c += rrrboth(A, B);
}
