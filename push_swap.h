/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:26:54 by adouay            #+#    #+#             */
/*   Updated: 2022/07/19 17:41:11 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack{
	int	n;
	int	index;
	struct	s_stack	*next;
}	t_stack;

long long int 	ft_atoi(const char *nptr);
int				check_args(char **argv);
t_stack 		*init(char **argv);

t_stack 		*create_node(int n);
t_stack			*ft_lstlast(t_stack *head);
int 			add_to_stack_a(t_stack **head, t_stack *node);

int				check_double(t_stack *a);

void			swap(t_stack **stack);

void			free_stack(t_stack *head);
#endif