/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalldigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:25:25 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/05 15:15:01 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

2 3 1

	2 1 3

	1 3 2

	int
	caseof3(t_stack_node *stack_a)
{
	int t1;
	int t2;
	int t3;

	t1 = ft_atoi(stack_a->content);
	t2 = ft_atoi(stack_a->next);
	t3 = ft_atoi(stack_a->next->next);

	if (t1 > t2 && t1 > t3)
	{
		ra_rb(stack_a);
		if (t2 < t3)
			sa_sb(stack_a);
	} // rotate stack 321 or 312

	if (t2 < t3)
	{
		sa_sb(stack_a);
	} //
}