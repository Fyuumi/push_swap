/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_etc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:53:08 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/03 17:58:54 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sa_sb(t_stack_node **stack_a) // sortingstack
{
	t_stack_node *first;
	t_stack_node *second;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	first->next->prev = first;
	*stack_a = second;
}

void	ra_rb(t_stack_node **stack_a) // rotatestack
{
	char *tempc;

	tempc = (*stack_a)->content;
	backnode(stack_a, tempc);
	pop(stack_a);
}
void	rr(t_stack_node *stack_a, t_stack_node *stack_b) // rotatebothstacks
{
	ra_rb(&stack_a);
	ra_rb(&stack_b);
}

void	pa_pb(t_stack_node *stack_from, t_stack_node *stack_to)
// pushtotoherstack
{
	char *temp;

	temp = stack_from->content;
	pop(&stack_from);
	printf("%s", temp);
	frontnode(stack_to, temp);
}
void	pop(t_stack_node **stack_a) // pops head
{
	t_stack_node *temp;

	temp = *stack_a;
	*stack_a = temp->next;
	(*stack_a)->prev = NULL;
	free(temp);
}
