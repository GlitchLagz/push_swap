/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:03:36 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/04 22:35:08 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	dig_check(char d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}

static void	num_check(char *s)
{
	if (*s == '-')
		s++;
	while (*s != '\0')
	{
		if (!dig_check(*s))
			err_msg();
		s++;
	}
}

static void	dup_check(int i, char **argv, long long res)
{
	int	ires;
	int	tmp;

	ires = (int)res;
	i++;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (tmp == ires)
			err_msg();
		i++;
	}
}

static void	range_check(char *s)
{
	long long	res;

	res = ft_atoll(s);
	if (res < -2147483648 || res > 2147483647)
		err_msg();
}

void	err_check(char **argv, int i)
{
	int			res;

	while (argv[i])
	{
		range_check(argv[i]);
		res = ft_atoi(argv[i]);
		dup_check(i, argv, res);
		num_check(argv[i]);
		i++;
	}
}
