/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:04:44 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/29 12:27:09 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftgnl.h"
#include <stdio.h>

char	*ft_push_swap(char **arr, int size)
{
	int	i;

	i = 1;
	printf("%d\n", (size - 1));
	while (i < size)
		printf("%s\n", arr[i++]);
	return ("ERROR");
}

int	main(int argc, char **argv)
{
	ft_push_swap(argv, argc);
	return (0);
}