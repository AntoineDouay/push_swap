/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:25:15 by adouay            #+#    #+#             */
/*   Updated: 2022/10/03 15:50:46 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(char **argv)
{
	int					i;
	long long int		n;
	
	t_stack *a;

	i = 1;
	a = create_node(ft_atoi(argv[i]));
	if (!a)
		return (NULL);
	while (argv[++i] != 0)
	{
		n = ft_atoi(argv[i]);
		if (n < -2147483648 || n > 2147483647)
			return (NULL);
		if (add_to_stack_a(&a, create_node(n)))
			return (NULL);
	}
	return (a);
}

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
	{
		free_stack(a);
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_double(a))
	{
		free_stack(a);
		write(1, "Error\n", 6);
		return (0);
	}
	t_stack	*b = NULL;
	get_index(a);
	if (is_sorted(&a))
		return (0);
	if (ft_lstsize(a) == 2)
		two_algo(&a);
	else if (ft_lstsize(a) == 3)
		three_algo(&a);
	else if (ft_lstsize(a) == 5)
		five_algo(&a, &b);
	else
		radix(&a, &b);
//	t_stack	*tmp = a;
//	while (tmp !=NULL)
//	{
//		printf("%i     index = %i\n", tmp->n, tmp->index);
//		tmp = tmp->next;
//	}
//	printf("---\nstack a\n");
//	tmp = b;
//	while (tmp !=NULL)
//	{
//		printf("%i     index = %i\n", tmp->n, tmp->index);
//		tmp = tmp->next;
//	}
//	printf("---\nstack b\n");
	free_stack (a);
	free_stack (b);
	return (0);
}