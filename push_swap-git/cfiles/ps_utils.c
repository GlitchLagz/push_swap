/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:00:18 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/04 22:18:50 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	putchr(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	if (nb < 0)
	{
		putchr('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		putchr(nb + 48);
}

t_list	*ft_lstnew(int nb)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->nxt = 0;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->nxt = new;
		}
		else
			*lst = new;
	}
}

int	ft_atoi(char *s)
{
	int	i;
	int	pon;
	int	res;

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
