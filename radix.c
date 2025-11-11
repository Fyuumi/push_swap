/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:50:32 by opaulman          #+#    #+#             */
/*   Updated: 2025/11/11 14:12:14 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	binaersize(int size)
{
	int	temp;
	int	i;

	i = 0;
	temp = size;
	while (temp > 1)
	{
		temp /= 2;
		i++;
	}
	return (i + 1);
}

// int	allina(t_stack_node **a, t_stack_node **b) // b to a
// {
// 	int pushed;

// 	pushed = 0;
// 	while (*b)
// 	{
// 		rra(a);
// 		pa(a, b);
// 		// printstack(*a);
// 		pushed++;
// 	}
// 	// ft_printf("\t^^^^%d pushed^^^^ \n", pushed);
// 	return (pushed);
// }
// int	allinb(t_stack_node **a, t_stack_node **b) // a to b
// {
// 	int pushed;

// 	pushed = 0;
// 	while (*a)
// 	{
// 		rrb(b);
// 		pb(a, b);
// 		// printstack(*a);
// 		pushed++;
// 	}
// 	// ft_printf("\t^^^^%d pushed^^^^ \n", pushed);
// 	return (pushed);
// }

// int	sort_a_to_b(t_stack_node **a, t_stack_node **b, int size, int mask)
// {
// 	int	i;
// 	int	flag;

// 	flag = 0;
// 	i = 0;
// 	while (i++ <= size && b)
// 	{
// 		rra(a);
// 		// //printstack(*a);
// 		// ft_printf("\n\tafter%d\n", (*a)->content);
// 		if (((*a)->content >> mask) & 1)
// 		{
// 			flag = 1;
// 			pb(a, b);
// 		}
// 	}
// 	// ft_printf("\t^^^^sorted^^^^\n");
// 	return (flag);
// }
// int	sort_b_to_a(t_stack_node **a, t_stack_node **b, int size, int mask)
// {
// 	int	i;
// 	int	flag;

// 	flag = 0;
// 	i = 0;
// 	while (i++ <= size && a)
// 	{
// 		rrb(b);
// 		// //printstack(*a);
// 		// ft_printf("\n\tafter%d\n", (*a)->content);
// 		if (((*b)->content >> mask) & 1)
// 		{
// 			flag = 1;
// 			pa(a, b);
// 		}
// 	}
// 	// ft_printf("\t^^^^sorted^^^^\n");
// 	return (flag);
// }

// int	algorithm(t_stack_node **a, t_stack_node **b, int size)
// {
// 	int	mask;

// 	// ft_printf("\n %d binaer algorithm:\n", i);
// 	mask = 0;
// 	while (checksorted(a) == 0)
// 	{
// 		sort_a_to_b(a, b, size, mask);
// 		allinb(a, b);
// 		mask++;
// 		if (checksorted(b) == 1)
// 		{
// 			allina(a, b);
// 			break ;
// 		}
// 		sort_b_to_a(a, b, size, mask);
// 		allina(a, b);
// 		mask++;
// 	}
// 	// ft_printf("\t^^^^ENDEEEE pushed^^^^ \n");
// 	return (1);
// }
int	algorithm(t_stack_node **a, t_stack_node **b, int size)
{
	int	bit;
	int	max_bits;
	int	count;

	max_bits = binaersize(size);
	bit = 0;
	while (bit < max_bits)
	{
		count = 0;
		while (count < size)
		{
			if (((*a)->content >> bit) & 1)
				ra(a); // Bit = 1 → nach hinten
			else
				pb(a, b); // Bit = 0 → nach B
			count++;
		}
		while (*b)
			pa(b, a); // alles zurück nach A
		bit++;
	}
	return (0);
}

// 3 digits binary off 999
// check 0 oder 1
// push if 1
// binary einen nach rechts verschieben zb 9 == 1001 danach 9 = 100