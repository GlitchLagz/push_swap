/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:33:34 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/01 20:30:00 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	ft_min_index(t_list **S)
{
	int		min_nb;
	int		min_pos;
	t_list	*tmp;

	tmp = *S;
	min_nb = tmp->nb;
	min_pos = tmp->pos;
	tmp = tmp->nxt;
	while (tmp != NULL)
	{
		if (tmp->nb < min_nb)
		{
			min_pos = tmp->pos;
			min_nb = tmp->nb;
		}
		tmp = tmp->nxt;
	}
	return (min_pos);
}

int	ft_mid_index(t_list **S)
{
	return (ft_lstsize(*S) / 2);
}

int	ft_max_index(t_list **S)
{
	int		max_nb;
	int		max_pos;
	t_list	*tmp;

	tmp = *S;
	max_nb = tmp->nb;
	max_pos = tmp->pos;
	tmp = tmp->nxt;
	while (tmp != NULL)
	{
		if (tmp->nb > max_nb)
		{
			max_pos = tmp->pos;
			max_nb = tmp->nb;
		}
		tmp = tmp->nxt;
	}
	return (max_pos);
}
