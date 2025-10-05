/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:55:16 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/05 14:42:32 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	isdigitasci(char **s) // output == 1 if just digits
{
	int i;
	int n;

	i = 1;
	n = 0;
	while (s[i])
	{
		while (s[i][n])
		{
			if (!(s[i][n] >= '0' && s[i][n] <= '9'))
				return (-1);
			n++;
		}
		n = 0;
		i++;
	}
	return (1);
}

int	duplicate_check(char **arr)
{
	int	i;
	int	j;

	j = 0;
	while (arr[j] != NULL)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			if (i != j)
			{
				if (ft_strlen(arr[j] == ft_strlen(arr[i])))
				{
					if (ft_strncmp(arr[j], arr[i], ft_strlen(arr[j])) == 0)
						return (-1); // duplicate found !!!
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
int	allready_sorted(char **arr)
{
	int	i;

	while (arr[i + 1] != NULL)
	{
		if (atoi(arr[i] > atoi(arr[i + 1])))
			return (1); // not sorted
	}
	return (-1); // sorted allready
}
int	error_check(char **arr, int numarguments)

{
	int i;

	if (numarguments == 0 || (numarguments == 1 && !arr[1]))
		return (printf("ERROR"), 1);
	if (numarguments == 1)
		// arr = ft_split(arr[1], '32')  Beispiel : "123 134 1321"
		printf("Arguments: %d\n", (numarguments));
	i = isdigitasci(arr); // i == 1 if just digits
	printf("1/-1: %i\n", i);
	if (i < 0)
		return (printf("ERROR"), 1);
	if (duplicate_check(arr) < 0)
		return (printf("Duplicate"), 1);
	if (allready_sorted(arr) < 0)
		return (printf("sorted"), 1);
	return (0);
}
