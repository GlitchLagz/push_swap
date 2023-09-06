/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 06:18:42 by tpawson           #+#    #+#             */
/*   Updated: 2023/09/06 18:16:48 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	ft_free(t_list *s, t_list *s2)
{
	t_list	*tmp;

	while (s != NULL)
	{
		tmp = s->nxt;
		free(s);
		s = tmp;
	}
	while (s2 != NULL)
	{
		tmp = s2->nxt;
		free(s2);
		s2 = tmp;
	}
	exit(0);
}

void	printstack(t_list *s)
{
	while (s != NULL)
	{
		putnbr(s->nb);
		s = s->nxt;
	}
}

void	err_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	arglen(char **nbrs)
{
	int	wc;

	wc = 0;
	while (nbrs[wc])
		wc++;
	return (wc + 1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		step_c;
	char	**nbrs;

	if (argc == 1)
		return (0);
	step_c = argc;
	if (argc == 2)
	{
		nbrs = ft_split(argv[1], ' ');
		argc = arglen(nbrs);
	}
	else
		nbrs = argv;
	if (step_c == 2)
		flood_a(&a, &b, nbrs, argc);
	else
		flood_a2(&a, &b, nbrs, argc);
	if (sort_check(a))
		ft_free(a, b);
	step_c = 0;
	begin_sort(&a, &b, &step_c);
	ft_free(a, b);
}
