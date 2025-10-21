/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:27:57 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/21 16:41:28 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "./printf/Libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack_node
{
	int					current_position;
	int					content;
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
// operations
void					ra_rb(t_stack_node **stack_a);
void					sa_sb(t_stack_node **stack_a);
void					rr(t_stack_node *stack_a, t_stack_node *stack_b);
void					pop(t_stack_node **stack_a);
void					pa_pb(t_stack_node **stack_from,
							t_stack_node **stack_to);
// createstack
void					printStack(t_stack_node *stack_b);
t_stack_node			*createnode(int content);
void					backnode(t_stack_node *a, int content);
void					frontnode(t_stack_node **stack_a, int content);
t_stack_node			*stackcreate(int *arr, t_stack_node **a);
// chartobinary
char					**arrtobin(int *arr, char **string);
int						*chartobinary(char **string);
char					*inttobinary(int value);
// smalldigits
int						smalldigits(int *bin, int size);
int						*caseof3(int *bin);
int						*array3change(int a, int b, int c);
// radix
int						push_test(t_stack_node **a, t_stack_node **b, int size);
// mapping
int						lenofstring(char **string);
int						searchforlowest(int *intarray, char *prozessflag);
int						mapping(char **string, int size, int *digits);
#endif