/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:07:35 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/21 16:08:11 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	checksorted(t_stack_node **a)
{
	int temp;
	t_stack_node *node;

	node = *a;
	temp = 9999;
	while (node->content != 0)
	{
		if ((node->content) > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}