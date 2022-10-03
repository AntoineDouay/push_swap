/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:21:51 by adouay            #+#    #+#             */
/*   Updated: 2022/10/03 16:11:13 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bit(t_stack *a)
{
//	int	max_int;
	int	max_index;
//	t_stack *tmp;
	int	i;

	max_index = ft_lstsize(a);
//	tmp = a;
	i = 0;
//	while(tmp->next != NULL)
//	{
//		if (tmp->index == max_index)
//		{
//			max_int = tmp->n;
//			break;
//		}
//		tmp = tmp->next;
//	}
	while((max_index>>i) != 0)
		i++;
	return (i);
}

void	radix(t_stack **a, t_stack **b)
{

	int	max_bit;
	int	i;
	int j;
	int size_a;

	max_bit = get_max_bit(*a);
	size_a = ft_lstsize(*a);
//	printf("max_bit : %i\n", max_bit);
//	printf("size a : %i\n", ft_lstsize((*a)));
//	printf("size b : %i\n", ft_lstsize((*b)));

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
//			j++;
		}
	//	printf("boucle b \n");
		while ((*b) != NULL)
			push(b, a, 'a');
		i++;
	//	printf("next round\n");
	//	printf("size a : %i\n", ft_lstsize((*a)));
	}
}