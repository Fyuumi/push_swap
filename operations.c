/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:53:08 by opaulman          #+#    #+#             */
/*   Updated: 2025/11/10 18:10:55 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack_node	*my_lstlast(t_stack_node *lst)
{
	t_stack_node	*last;
	t_stack_node	*temp;
	int				i;

	if (!lst)
		return (NULL);
	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	last = lst;
	while (i > 1)
	{
		last = last->next;
		i--;
	}
	return (last);
}

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

// void	ra_rb(t_stack_node **stack_a, char *c) // rotatestack
// {
// 	int tempc;

// 	ft_printf("%s\n", c);
// 	tempc = (*stack_a)->content;
// 	backnode(*stack_a, tempc);
// 	pop(stack_a);
// }
void	ra_rb(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ; // nichts zu rotieren
	first = *stack;
	last = my_lstlast(*stack); // letzte Node
	*stack = first->next;      // Kopf nach hinten schieben
	(*stack)->prev = NULL;     // neuer Kopf hat kein prev
	last->next = first;        // alter Kopf ans Ende hängen
	first->prev = last;
	first->next = NULL; // alter Kopf ist jetzt letzter
}

// int	rra(t_stack_node **a, char *c)
// {
// 	int				tempc;
// 	t_stack_node	*temp;
// 	t_stack_node	*cut;

// 	if (((*a)->prev == NULL) && ((*a)->next == NULL))
// 		return (1);
// 	ft_printf("%s\n", c);
// 	tempc = (my_lstlast(*a)->content);
// 	temp = (my_lstlast(*a));
// 	frontnode(a, tempc);
// 	if (temp->prev)
// 	{
// 		cut = temp->prev;
// 		cut->next = NULL;
// 	}
// 	free(temp);
// 	if ((*a)->next)
// 		(*a)->next->prev = *a;
// 	return (0);
// }

int	rra_rrb(t_stack_node **a)
{
	t_stack_node	*temp;
	t_stack_node	*cut;

	if (((*a)->prev == NULL) && ((*a)->next == NULL))
		return (1);
	temp = my_lstlast(*a);
	cut = temp->prev;
	cut->next = NULL;
	temp->prev = NULL;
	temp->next = *a;
	(*a)->prev = temp;
	*a = temp;
	return (0);
}

void	pa_pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
}
void	pop(t_stack_node **a) // pops head
{
	t_stack_node *temp;

	temp = *a;
	if (temp->next == NULL)
		*a = NULL;
	else
	{
		*a = temp->next;
		(*a)->prev = NULL;
	}
	free(temp);
}
