/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:50:32 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/21 15:58:09 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	push_test(t_stack_node **a, t_stack_node **b, int size)
{
	int	i;

	// special stuff for 3 and 5 digits
	// 	indexing
	//	bits
	i = 0;
	while (i++ < size)
	{
		if ((*a)->content & 1)
		{
			pa_pb(*a, *b);
		}
		else
			ra_rb(a);
	}
	(*a)->content <<= 1;
	return (1);
}

// 3 digits binary off 999
// check 0 oder 1
// push if 1
// binary einen nach rechts verschieben zb 9 == 1001 danach 9 = 100