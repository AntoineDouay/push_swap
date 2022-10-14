/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:25:15 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 17:10:42 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*tmp;
	int		sorted;

	sorted = 1;
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->next != NULL)
			if (tmp->index > tmp->next->index)
				sorted = 0;
		tmp = tmp->next;
	}
	return (sorted);
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
			break ;
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

void	which_algo(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		two_algo(a);
	else if (ft_lstsize(*a) == 3)
		three_algo(a);
	else if (ft_lstsize(*a) == 4)
		four_algo(a, b);
	else if (ft_lstsize(*a) == 5)
		five_algo(a, b);
	else
		radix(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (argc == 1)
		return (0);
	if (check_args(argv + 1))
		return (error_exit(a));
	a = init(argv + 1);
	if (!a)
		return (error_exit(a));
	if (check_double(a))
		return (error_exit(a));
	get_index(a);
	if (is_sorted(&a))
	{
		free_stack(a);
		return (0);
	}
	which_algo(&a, &b);
	free_stack(a);
	return (0);
}

//	t_stack	*tmp = a;
//	while (tmp !=NULL)
//	{
//		printf("%i     index = %i\n", tmp->n, tmp->index);
//		tmp = tmp->next;
//	}
//	printf("---\nstack a\n");