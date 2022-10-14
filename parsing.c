/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:35:58 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 17:44:34 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *argv)
{
	if (*argv == '-')
		argv++;
	if (!*argv)
		return (1);
	while (*argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
		argv++;
	}
	return (0);
}

int	check_double(t_stack *a)
{
	t_stack	*cpy;
	int		tmp;

	while (a != NULL)
	{	
		tmp = a->n;
		cpy = a->next;
		if (!cpy)
			break ;
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

int	check_args(char **args)
{
	int				i;
	long long int	tmp;

	i = 0;
	tmp = 0;
	while (args[i] != 0)
	{
		if (check_int(args[i]))
			return (1);
		tmp = ft_atoi(args[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}
