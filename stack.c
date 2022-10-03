/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:14:06 by adouay            #+#    #+#             */
/*   Updated: 2022/10/03 14:26:31 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if(!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	if(tmp)
		while (tmp->next != NULL)
			tmp = tmp->next;
	return (tmp);
}

t_stack	*ft_lstsecondlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	if(tmp)
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

int	ft_lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}