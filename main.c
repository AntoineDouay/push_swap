/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:25:15 by adouay            #+#    #+#             */
/*   Updated: 2022/07/19 17:42:02 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(char **argv)
{
	int	i;
	t_stack *a;

	i = 1;
	a = create_node(ft_atoi(argv[i]));
	if (!a)
		return (NULL);
	while (argv[++i] != 0)
		if (add_to_stack_a(&a, create_node(ft_atoi(argv[i]))))
			return (NULL);
	return (a);
}

void	get_index(t_stack *a)
{
	t_stack	*cpy;
	t_stack	*head;
	int		tmp;
	int		i;

	i = 1;
	head = a;
	while (a != NULL)
	{
		tmp = a->n;
		cpy = head;
		if (!cpy)
			break;
		while (cpy != NULL)
		{
			if (tmp > cpy->n)
				i++;
			cpy = cpy->next;
		}
		a->index = i;
		i = 1;
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (check_args(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	t_stack	*a;
	a = init(argv);
	if (!a)
		return (0);
	if (check_double(a))
	{
		free_stack(a);
		write(1, "Error\n", 6);
		return (0);
	}
	get_index(a);
//	swap(&a);
	while (a !=NULL)
	{
		printf("%i     index = %i\n", a->n, a->index);
		a = a->next;
	}
	free_stack (a);
	return (0);
}