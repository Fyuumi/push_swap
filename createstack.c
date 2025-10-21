/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:51:12 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/21 16:01:11 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	printStack(t_stack_node *stack_b)
{
	while (stack_b)
	{
		printf("\n%d\n", stack_b->content);
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
t_stack_node	*createnode(int content)
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
void	backnode(t_stack_node *stack_a, int content)
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

void	frontnode(t_stack_node **stack_a, int content)
{
	t_stack_node	*first;

	first = createnode(content);
	first->next = *stack_a;
	*stack_a = first;
}
t_stack_node	*stackcreate(int *arr, t_stack_node **a)
{
	int i;

	i = 0;
	if (arr == NULL)
		return (*a);
	*a = createnode(arr[i++]); // headcreate
	while (arr[i])
	{
		backnode(*a, arr[i++]);
	}
	return (*a);
}