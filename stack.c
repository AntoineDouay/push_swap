/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:14:06 by adouay            #+#    #+#             */
/*   Updated: 2022/07/19 17:41:28 by adouay           ###   ########.fr       */
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

int	add_to_stack_a(t_stack **head, t_stack *node)
{
	t_stack	*tmp;
	if (*head == NULL)
	{
		*head = node;
	}
	else if (node)
	{
		tmp = ft_lstlast(*head);
		tmp->next = node;
	}
	else
		return (1);
	return (0);
}