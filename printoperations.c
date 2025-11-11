/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:05:31 by opaulman          #+#    #+#             */
/*   Updated: 2025/11/10 18:27:44 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rra(t_stack_node **a)
{
	rra_rrb(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rra_rrb(b);
	ft_printf("rrb\n");
}
void	ra(t_stack_node **a)
{
	ra_rb(a);
	ft_printf("ra\n");
}
void	rb(t_stack_node **b)
{
	ra_rb(b);
	ft_printf("rb\n");
}
void	pa(t_stack_node **a, t_stack_node **b)
{
	pa_pb(a, b);
	ft_printf("pa\n");
}
void	pb(t_stack_node **b, t_stack_node **a)
{
	pa_pb(b, a);
	ft_printf("pb\n");
}
void	sa(t_stack_node **a)
{
	sa_sb(a);
	ft_printf("sa\n");
}
void	sb(t_stack_node **b)
{
	sa_sb(b);
	ft_printf("sb\n");
}
