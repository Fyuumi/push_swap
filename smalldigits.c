/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalldigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:25:25 by opaulman          #+#    #+#             */
/*   Updated: 2025/11/10 18:23:20 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	array3change(int *array, int a, int b, int c)
{
	array[0] = a;
	array[1] = b;
	array[2] = c;
	return ;
}
int	*caseof3(int *bin)
{
	if (bin[2] < bin[1] && bin[2] > bin[0]) // 021
	{
		ft_printf("sa\n");
		array3change(bin, bin[1], bin[0], bin[2]);
	}
	if (bin[0] > bin[1] && bin[0] > bin[2]) // 210 or 201
	{
		ft_printf("ra\n");
		array3change(bin, bin[1], bin[2], bin[0]);
	}
	if (bin[0] < bin[1] && bin[1] > bin[2]) // 120
	{
		ft_printf("rra\n");
		array3change(bin, bin[2], bin[0], bin[1]);
	}
	if (bin[0] > bin[1] && bin[0] < bin[2]) // 102
	{
		array3change(bin, bin[1], bin[0], bin[2]);
		ft_printf("sa\n");
	}
	return (bin);
}
void	stackcas3(t_stack_node **a)
{
	if (((*a)->content == 1) && ((*a)->next->content == 3)) // 132 --> 312
		sa(a);
	if ((*a)->content == 3) // 321 or 312 --> 213 or 123
		ra(a);
	if (((*a)->content == 2) && ((*a)->next->content == 3)) // 231 -> 123
		rra(a);
	if ((*a)->content == 2) // 213 -> 123
		sa(a);
}

int	caseof4(t_stack_node **a, t_stack_node **b)
{
	while (true)
	{
		if ((*a)->content == 4)
		{
			pb(a, b);
			break ;
		}
		else
			ra(a);
	}
	stackcas3(a);
	pa(b, a);
	ra(a);
	return (0);
}
void	caseof5(t_stack_node **a, t_stack_node **b)
{
	int	flag;

	flag = 0;
	while (flag < 2)
	{
		if ((*a)->content == 5 || (*a)->content == 4)
		{
			pb(a, b);
			flag++;
		}
		else
			ra(a);
	}
	stackcas3(a);
	pa(b, a);
	pa(b, a);
	if ((*a)->content > (*a)->next->content) // 4 on top
		sa(a);
	ra(a);
	ra(a);
	// printstack(*a);
}

int	smalldigits(int *bin, int size)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	// ft_printf("\nsmalldigits:\nsize: %d\n");
	if (size == 2)
	{
		ft_printf("sa");
		exit(1);
	}
	if (size == 3)
	{
		caseof3(bin);
		exit(1);
	}
	stackcreate(bin, &a, size);
	if (size == 4)
		caseof4(&a, &b);
	if (size == 5)
		caseof5(&a, &b);
	free(a);
	free(b);
	exit(1);
}
