/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:21:51 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 17:10:03 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	five_algo2(t_stack **a, t_stack **b, t_stack **tmp)
{
	if ((*tmp)->index == 4 || (*tmp)->index == 5)
	{
		while ((*tmp)->index != (*a)->index)
			rotate(a, 'a');
		if ((*tmp)->next != NULL)
			(*tmp) = (*tmp)->next;
		push(a, b, 'b');
		return (1);
	}
	return (0);
}

void	five_algo(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i < 5)
	{
		if (five_algo2(a, b, &tmp))
			i = 0;
		else
		{
			if (tmp->next != NULL)
				tmp = tmp->next;
			i++;
		}
	}
	three_algo(a);
	if ((*b)->index == 4)
		swap(b, 'b');
	push(b, a, 'a');
	push(b, a, 'a');
	rotate(a, 'a');
	rotate(a, 'a');
}

int	get_max_bit(t_stack *a)
{
	int	max_index;
	int	i;

	max_index = ft_lstsize(a);
	i = 0;
	while ((max_index >> i) != 0)
		i++;
	return (i);
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_bit;
	int	i;
	int	j;
	int	size_a;

	max_bit = get_max_bit(*a);
	size_a = ft_lstsize(*a);
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j++ < size_a)
		{
			if ((((*a)->index >> i) & 1) == 1)
				rotate(a, 'a');
			else
				push(a, b, 'b');
		}
		while ((*b) != NULL)
			push(b, a, 'a');
		i++;
	}
}
