/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:27:57 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/05 15:15:47 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "./printf/Libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack_node
{
	int					current_position;
	char				*content;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// push_swap
int						main(int argc, char **argv);
// error check
int						duplicate_check(char **arr);
int						allready_sorted(char **arr);
int						isdigitasci(char **s);
int						error_check(char **arr, int size);
// rs_etc
void					ra_rb(t_stack_node **stack_a);
void					sa_sb(t_stack_node **stack_a);
void					rr(t_stack_node *stack_a, t_stack_node *stack_b);
void					pop(t_stack_node **stack_a);
void					pa_pb(t_stack_node *stack_from, t_stack_node *stack_to);
// createstack
void					printStack(t_stack_node *stack_b);
t_stack_node			*createnode(char *content);
void					backnode(t_stack_node *a, char *content);
t_stack_node			stackcreate(char **arr);
// chartobinary
char					**chartobinary(char **string);
char					*inttoBinary(int value);
// smalldigits
int						caseof3(t_stack_node *stack_a);
// radix
int						push_test(stack_a, stack_b);
#endif