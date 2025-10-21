/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalldigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:25:25 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/21 16:43:36 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	*caseof3(int *bin)
{
	if (bin[2] < bin[1] && bin[2] > bin[0]) // 021
	{
		ft_printf("sa");
		bin = array3change(bin[1], bin[0], bin[2]);
	}
	if (bin[0] > bin[1] && bin[0] > bin[2]) // 210 or 201
	{
		ft_printf("ra");
		bin = array3change(bin[2], bin[0], bin[1]);
	}
	if (bin[0] < bin[1] && bin[1] > bin[2]) // 120
	{
		ft_printf("rra");
		bin = array3change(bin[1], bin[2], bin[0]);
	}
	if (bin[0] > bin[1] && bin[0] < bin[2]) // 102
		bin = array3change(bin[1], bin[0], bin[2]);
	ft_printf("sa");
	return (bin);
}

int	caseof5(int *bin) // need case of 4
{
	int temp;
	int *tempstackb;

	tempstackb = NULL;
	if (bin[0] == 4 || bin[0] == 3)
	{
		ft_printf("ra");
		temp = bin[0];
		bin = array3change(bin[1], bin[2], bin[3]);
		bin[3] = bin[4];
		bin[4] = temp;
	}
	if (bin[4] == 0 || bin[4] == 1)
	{
		ft_printf("rra");
		temp = bin[2];
		bin = array3change(bin[4], bin[0], bin[1]);
		bin[4] = bin[3];
		bin[3] = temp;
	}
	if (bin[0] == 0 || bin[0] == 1)
	{
		ft_printf("pb");
		tempstackb[0] = bin[0];
		bin = array3change(bin[1], bin[2], bin[3]);
		bin[3] = bin[4];
	}
	caseof3(bin);
	return (0);
}
int	smalldigits(int *bin, int size)
{
	if (size == 3)
		caseof3(bin);
	if (size == 5)
		caseof5(bin);
	return (0);
}

int	*array3change(int a, int b, int c)
{
	int *array;

	array = NULL;
	array[0] = a;
	array[1] = b;
	array[2] = c;
	return (array);
}