/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:33:34 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/06 19:06:20 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	while_ra(t_list **A, int ro, int *step_c)
{
	int	i;

	i = -1;
	while (++i < ro)
		*step_c += ra(A);
}

void	while_rb(t_list **B, int ro, int *step_c)
{
	int	i;

	i = -1;
	while (++i < ro)
		*step_c += rb(B);
}

void	rr_stacks(t_list **A, t_list **B, int ro, int *step_c)
{
	int	i;

	i = -1;
	while (++i < ro)
		*step_c += rrboth(A, B);
}
