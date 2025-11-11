/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:51:12 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/25 17:19:55 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	printstack(t_stack_node *stack)
{
	t_stack_node	*temp;
	int				i;

	i = 0;
	temp = stack;
	while (temp)
	{
		i++;
		ft_printf("%d\t", temp->content);
		temp = temp->next;
		if (i == 0)
		{
			ft_printf("\n");
			i = 0;
		}
	}
	ft_printf("\n");
}
t_stack_node	*createnode(int content)
{
	t_stack_node	*node;

	node = NULL;
	node = malloc(sizeof(t_stack_node));
	if (!node)
	{
		ft_printf("\nmallocerror!!!!\n");
		exit(1);
	}
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
	while (last->next) // last node
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
	if (*stack_a)
	{
		first->next = *stack_a;
		(*stack_a)->prev = first;
	}
	*stack_a = first;
}
t_stack_node	*stackcreate(int *arr, t_stack_node **a, int size)
{
	int i;

	i = 0;
	*a = createnode(arr[i++]); // headcreate
	while (i < size)
		backnode(*a, arr[i++]); // appendnodes
	// ft_printf("\nstackcheck:\n");
	// printstack(*a);
	return (*a);
}