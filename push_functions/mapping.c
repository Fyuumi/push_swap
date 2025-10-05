/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:59:29 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/05 17:07:57 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	lenofstring(char **string)
{
	int	i;

	i = 0;
	while (string[i] != NULL)
		i++;
	return (i);
}
int	searchforlowest(int *intarray, char *prozessflag)
{
	int	i;
	int	lowest;
	int	positionofint;

	positionofint = 0;
	i = 0;
	lowest = intarray[i];
	while (intarray[i])
	{
		if ((intarray[i] < lowest) && (prozessflag[i] = 0))
		{
			lowest = intarray[i];
			positionofint = i;
		}
		i++;
	}
	return (positionofint);
}
int	*mapping(char **string, int size) // sizeofstring
{
	int *intarray[size];
	int digit;
	int positionofint;
	char *prozessflag;

	digit = 0;
	while (string[digit])
		intarray[digit] = ft_atoi(string[digit++]);
	prozessflag = ft_calloc(size, sizeof(char));
	if (!prozessflag)
		return (1);
	digit = 0;
	while (digit < size)
	{
		positionofint = searchforlowest(intarray, prozessflag);
		intarray[positionofint] = digit;
		prozessflag[positionofint] = 1;
		digit++;
	}
	return (free(prozessflag), intarray);
}
