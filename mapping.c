/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:59:29 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/26 19:52:49 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	lowest(int *intarray, char *prozessflag, int size)
{
	int	i;
	int	lowest;
	int	positionofint;

	positionofint = 0;
	i = 0;
	lowest = 2147483647;
	while (size > i)
	{
		if ((intarray[i] < lowest) && (prozessflag[i] != '1'))
		{
			lowest = intarray[i];
			positionofint = i;
		}
		i++;
	}
	return (positionofint);
}
int	mapping(char **string, int size, int *intarray) // sizeofstring
{
	int digit;
	int positionofint;
	char *prozessflag;

	digit = 0;
	while (string[digit] != NULL)
	{
		intarray[digit] = ft_atoi(string[digit]);
		digit++;
	}
	prozessflag = ft_calloc(size, sizeof(char));
	if (!prozessflag)
		return (1);
	digit = 0;
	while (digit < size)
	{
		positionofint = lowest(intarray, prozessflag, size);
		intarray[positionofint] = digit + 1;
		prozessflag[positionofint] = '1';
		digit++;
	}
	// ft_printf("\nflag: %s\n", prozessflag);
	return (free(prozessflag), 0);
}
