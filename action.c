/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:51:23 by adouay            #+#    #+#             */
/*   Updated: 2022/07/19 16:37:19 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	//if (stack == NULL|| stack->next == NULL)
	//	return ;
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;


	//tmp.n = stack->n;
	//tmp.index = stack->index;

	//stack->n = stack->next->n;
//	stack->index = stack->next->index;

//	stack->next->n = tmp.n;
//	stack->next->index = tmp.index;
}
/*
void	swapswap(t_stack *stack, t_stack *stack1)
{
	swap(from);
	swap(to);
}

void	push(t_stack **from, t_stack **to)
{

}

void	rotate()
*/
