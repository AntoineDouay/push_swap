/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:50:36 by adouay            #+#    #+#             */
/*   Updated: 2022/10/03 13:52:29 by adouay           ###   ########.fr       */
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
	if((*a)->index == 1 && (*a)->next->index != 2)
	{
		swap(a, 'a');
		rotate(a, 'a');
		return ;
	}
	else if((*a)->index == 2 && (*a)->next->index == 1)
		return (swap(a, 'a'));
	else if((*a)->index == 2 && (*a)->next->index == 3)	
		return (rev_rotate(a, 'a'));
	else if((*a)->index == 3 && (*a)->next->index == 2)
	{
		swap(a, 'a');
		return (rev_rotate(a, 'a'));
	}
	else if((*a)->index == 3 && (*a)->next->index == 1)
		return (rotate(a, 'a'));
	else
		return ; 
}

void five_algo(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i < 5)
	{
		if (tmp->index == 4 || tmp->index == 5)
		{
			if (i == 2 || i == 1)
			{
				if (i == 2)
					rotate(a, 'a');
				rotate(a, 'a');
			}
			else if (i == 3 || i == 4)
			{
				if (i == 3)
					rev_rotate(a, 'a');
				rev_rotate(a, 'a');
			}
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
	if ((*b)->index == 4)
		swap(b, 'b');
	push(b, a, 'b');
	push(b, a, 'b');
	rotate(a, 'a');
	rotate(a, 'a');
}

/*

1 2 3  						|	0	|
1 3 2 	sa ra				|	1	|

2 1 3	sa					|	1	|
2 3 1	rra					|	1	|

3 2 1   sa ra 				|	2	|
3 1 2	ra					|	1	|

*/
