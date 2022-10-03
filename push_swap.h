/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:26:54 by adouay            #+#    #+#             */
/*   Updated: 2022/10/03 13:54:20 by adouay           ###   ########.fr       */
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
t_stack  		*ft_lstlast(t_stack *stack);
t_stack  		*ft_lstsecondlast(t_stack *stack);
int				ft_lstsize(t_stack *stack);
t_stack 		*init(char **argv);

t_stack 		*create_node(int n);
int 			add_to_stack_a(t_stack **head, t_stack *node);

int				check_double(t_stack *a);

void			swap(t_stack **stack, char c);
void    		push(t_stack **from, t_stack **to, char c);
void			rotate(t_stack **stack, char c);
void			rev_rotate(t_stack **stack, char c);

void			two_algo(t_stack **a);
void			three_algo(t_stack **a);
void			five_algo(t_stack **a, t_stack **b);
void			radix(t_stack **a, t_stack **b);

void			free_stack(t_stack *head);
#endif