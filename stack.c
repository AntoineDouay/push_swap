/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:14:06 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 17:05:01 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(char **args)
{
	int					i;
	long int			n;
	t_stack				*a;

	i = 0;
	a = create_node(ft_atoi(args[i]));
	if (!a)
		return (NULL);
	while (args[++i] != 0)
	{
		n = ft_atoi(args[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (NULL);
		if (add_to_stack_a(&a, create_node(n)))
			return (NULL);
	}
	return (a);
}

t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstsecondlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	if (tmp)
		while (tmp->next->next != NULL)
			tmp = tmp->next;
	return (tmp);
}

int	add_to_stack_a(t_stack **head, t_stack *node)
{
	t_stack	*tmp;

	if (*head == NULL)
		*head = node;
	else if (node)
	{
		tmp = ft_lstlast(*head);
		tmp->next = node;
	}
	else
		return (1);
	return (0);
}
