/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:51:23 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 15:42:17 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push(t_stack **from, t_stack **to, char c)
{
	t_stack	*tmp;

	tmp = (*from);
	(*from) = (*from)->next;
	tmp->next = (*to);
	(*to) = tmp;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*last;

	last = ft_lstlast(*stack);
	tmp = (*stack);
	(*stack) = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rev_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*second_last;

	last = ft_lstlast((*stack));
	second_last = ft_lstsecondlast((*stack));
	last->next = (*stack);
	(*stack) = last;
	second_last->next = NULL;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
