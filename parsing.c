/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:35:58 by adouay            #+#    #+#             */
/*   Updated: 2022/07/19 02:01:52 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *argv)
{
	if (*argv == '-')
		argv++;
	while(*argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
		argv++;
	}
	return (0);
}

int	check_double(t_stack *a)
{
	t_stack *cpy;
	int		tmp;
	while (a != NULL)
	{	
		tmp = a->n;
		cpy = a->next;
		if (!cpy)
			break;
		while (cpy != NULL)
		{
			if (tmp == cpy->n)
				return (1);
			cpy = cpy->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_args(char **argv)
{
	int				i;
	long long int	tmp;

	i = 1;
	tmp = 0;
	while (argv[i] != 0)
	{
		if (check_int(argv[i]))
			return (1);
		tmp = ft_atoi(argv[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}