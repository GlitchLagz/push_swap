/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:34:19 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/06 17:53:49 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

//initilizing functions for pushing the numbers inputed 
//to stack A and assigning them a position/index.

void	lst_swap(t_list **prev, t_list **tmp)
{
	*prev = *tmp;
	*tmp = NULL;
}

void	ft_free_err(t_list **A, t_list **B)
{
	err_msg();
	ft_free(*A, *B);
}

void	flood_a(t_list **A, t_list **B, char **argv, int argc)
{
	int		i;
	t_list	*tmp;
	t_list	*prev;

	err_check(argv, 0);
	i = 0;
	prev = NULL;
	tmp = NULL;
	while (i < argc - 1)
	{
		tmp = ft_lstnew_and_pos(ft_atoi(argv[i]), i);
		if (!tmp)
			ft_free_err(A, B);
		if (prev && tmp->pos != 0)
		{
			tmp->pre = prev;
			tmp->pre->nxt = tmp;
		}
		ft_lstadd_back(A, tmp);
		if (i + 2 == argc)
			tmp->nxt = NULL;
		else
			lst_swap(&prev, &tmp);
		i++;
	}
}

void	flood_a2(t_list **A, t_list **B, char **argv, int argc)
{
	int		i;
	t_list	*tmp;
	t_list	*prev;

	err_check(argv, 1);
	i = 1;
	prev = NULL;
	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew_and_pos(ft_atoi(argv[i]), i - 1);
		if (!tmp)
			ft_free_err(A, B);
		if (prev && tmp->pos != 0)
		{
			tmp->pre = prev;
			tmp->pre->nxt = tmp;
		}
		ft_lstadd_back(A, tmp);
		if (i + 1 == argc)
			tmp->nxt = NULL;
		else
			lst_swap(&prev, &tmp);
		i++;
	}
}
