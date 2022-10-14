/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:50:36 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 16:06:02 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_algo(t_stack **a)
{
	if ((*a)->index == 2)
		swap(a, 'a');
}

void	three_algo(t_stack **a)
{
	if ((*a)->index == 1 && (*a)->next->index != 2)
	{
		swap(a, 'a');
		rotate(a, 'a');
		return ;
	}
	else if ((*a)->index == 2 && (*a)->next->index == 1)
		return (swap(a, 'a'));
	else if ((*a)->index == 2 && (*a)->next->index == 3)
		return (rev_rotate(a, 'a'));
	else if ((*a)->index == 3 && (*a)->next->index == 2)
	{
		swap(a, 'a');
		return (rev_rotate(a, 'a'));
	}
	else if ((*a)->index == 3 && (*a)->next->index == 1)
		return (rotate(a, 'a'));
	else
		return ;
}

int	four_algo2(t_stack **a, t_stack *tmp, int i)
{	
	if (tmp->index == 4)
	{
		if (i == 1)
			rotate(a, 'a');
		if (i == 2)
		{
			rotate(a, 'a');
			rotate(a, 'a');
		}
		if (i == 3)
			rev_rotate(a, 'a');
		return (1);
	}
	return (0);
}

void	four_algo(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i < 4)
	{
		if (four_algo2(a, tmp, i))
		{
			if (tmp->next != NULL)
				tmp = tmp->next;
			push(a, b, 'b');
			i = 0;
		}
		else
		{
			if (tmp->next != NULL)
				tmp = tmp->next;
			i++;
		}
	}
	three_algo(a);
	push(b, a, 'a');
	rotate(a, 'a');
}
