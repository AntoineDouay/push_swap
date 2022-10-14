/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:26:54 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 17:11:08 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

/* ----- main.c ----- */
int				is_sorted(t_stack **a);
void			get_index(t_stack *a);
void			which_algo(t_stack **a, t_stack **b);

/* ----- parsing.c ----- */
int				check_int(char *argv);
int				check_double(t_stack *a);
int				check_args(char **arg);

/* ----- stack.c ----- */
t_stack			*init(char **argv);
t_stack			*create_node(int n);
t_stack			*ft_lstsecondlast(t_stack *stack);
int				add_to_stack_a(t_stack **head, t_stack *node);

/* ----- algo.c ----- */
void			two_algo(t_stack **a);
void			three_algo(t_stack **a);
void			four_algo(t_stack **a, t_stack **b);
int				four_algo2(t_stack **a, t_stack *tmp, int i);
void			five_algo(t_stack **a, t_stack **b);

/* ----- algo2.c ----- */
void			five_algo(t_stack **a, t_stack **b);
int				five_algo2(t_stack **a, t_stack **b, t_stack **tmp);
int				get_max_bit(t_stack *a);
void			radix(t_stack **a, t_stack **b);

/* ----- action.c ----- */
void			swap(t_stack **stack, char c);
void			push(t_stack **from, t_stack **to, char c);
void			rotate(t_stack **stack, char c);
void			rev_rotate(t_stack **stack, char c);

/* ----- free.c ----- */
int				error_exit(t_stack *a);
void			free_stack(t_stack *head);

#endif
