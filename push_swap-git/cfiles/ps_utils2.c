/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:19:52 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/04 22:21:40 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->nxt)
			lst = lst->nxt;
		else
			return (lst);
	}
	return (NULL);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->nxt = *lst;
		*lst = new;
	}
}

void	ft_lstremove_first(t_list **lst)
{
	t_list	*tmp;
	t_list	*cur;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = tmp->nxt;
	if (*lst)
		(*lst)->pre = NULL;
	free (tmp);
	cur = *lst;
	while (cur != NULL)
	{
		cur->pos = (cur->pos) - 1;
		cur = cur->nxt;
	}
}

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->nxt;
		i++;
	}
	return (i);
}

long	ft_atoll(char *s)
{
	int		i;
	int		pon;
	long	res;

	pon = 1;
	res = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\n')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			pon = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - 48);
		i++;
	}
	return (res * pon);
}
