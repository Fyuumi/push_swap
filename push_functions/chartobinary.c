/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartobinary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:33:49 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/05 17:27:13 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	*inttobinary(int value)
{
	int		i;
	char	*bin;
	int		size;

	size = value;
	i = 0;
	while (size > 0)
	{
		size /= 2;
		i++;
	}
	size = i;
	bin = ft_calloc(size + 1, 1);
	if (!bin)
		return (NULL);
	ft_memset(bin, '0', size);
	while (i > 0)
	{
		if (value & 1)
			bin[size - i] = '1';
		value >>= 1;
		i--;
	}
	bin[size] = '\0';
	return (bin);
}

char	**chartobinary(char **string)
{
	int		i;
	int		*intarray;
	char	**binarystring;

	i = 0;
	binarystring = ft_strdup(string);
	if (!binarystring)
		return (NULL);
	while (string[i] != NULL)
	{
		intarray[i] = ft_atoi(string[i]);
		binarystring[i] = inttoBinary(intarray[i]);
		if (!binarystring[i])
			return (free(binarystring), NULL); // if allocation went wrong
	}
	return (binarystring);
}

char	**arrtobin(int *arr, char **string)
{
	int i;

	i = 0;
	while (arr[i])
	{
		string[i] = inttobinary(arr[i]);
		if (!string[i])
			return (1);
		i++;
	}
	return (string);
}