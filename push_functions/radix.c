/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:50:32 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/03 17:59:47 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	push_test(stack_a, stack_b)
{
	// special stuff for 3 and 5 digits
	// 	indexing?
	//	bits?

	static int j; // how many digits checked
	int i;        // last digit
	int n;        // tests 9 to 0
	char *nodeinput;

	n = 9;
	while (j != i) // last digit to first
	{
		while (stack_a) // geht alle nodes durch, bis alle in stack_b sind
		{
			while (n >= 0)
			{
				// nodeinput = node-> Top;
				// einen String = die node oben im Stack
				i = ft_strlen(nodeinput);
				if (nodeinput[i - j] == n) // wenn die Node bzw der String,
				{
					stackswap();
					//  an der hintersten Minus den jeweiligen Durchgang
					break ;
					//      == n ist push die node zum anderen stack. (TREFFER)
				}
				n--;
			}
			// Node = NULL im ersten Stack weil gepusht zu B
			stackrotate();
		}
		j++;
	}
}