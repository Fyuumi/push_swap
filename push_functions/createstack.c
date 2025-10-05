/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:51:12 by opaulman          #+#    #+#             */
/*   Updated: 2025/09/17 16:15:34 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	printStack(t_stack_node *stack_b)
{
	while (stack_b)
	{
		printf("\n%s\n", stack_b->content);
		stack_b = stack_b->next;
		stack_b = stack_b->next;
		stack_b = stack_b->prev;
	}
	// stack_b = stack_b->prev;
	// while (stack_b)
	// {
	// 	printf("\n%s\n", stack_b->content);
	// 	stack_b = stack_b->prev;
	// }
	printf("NULL\n");
}
t_stack_node	*createnode(char *content)
{
	t_stack_node	*node;

	node = NULL;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
void	backnode(t_stack_node *stack_a, char *content)
{
	t_stack_node	*last;
	t_stack_node	*new;

	last = stack_a;
	while (last->next) // last stuff
		last = last->next;
	new = createnode(content);
	last->next = new;
	new->prev = last;
	last->next->next = NULL;
}

void	frontnode(t_stack_node **stack_a, char *content)
{
	t_stack_node	*first;

	first = createnode(content);
	first->next = *stack_a;
	*stack_a = first;
}
t_stack_node	stackcreate(char **arr)
{
	int i;
	t_stack_node *stack_a;

	i = 0;
	stack_a = createnode(arr[i++]); // headcreate
	stack_a->prev = NULL;
	while (arr[i])
	{
		backnode(stack_a, arr[i++]);
	}
	return (*stack_a);
}