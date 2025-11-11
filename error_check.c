/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:55:16 by opaulman          #+#    #+#             */
/*   Updated: 2025/11/10 13:42:55 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	isdigitasci(char **s) // output == 1 if just digits
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i][n])
		{
			if (!(s[i][n] >= '0' && s[i][n] <= '9'))
				if (!(s[i][n] == '-'))
				{
					return (-1);
				}
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
				if ((ft_strlen(arr[j]) == (ft_strlen(arr[i]))))
				{
					if (ft_strncmp(arr[j], arr[i], (ft_strlen(arr[j]))) == 0)
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

	i = 0;
	while (arr[i + 1] != NULL)
	{
		if (ft_atoi(arr[i]) == 0)
			exit(ft_printf("ERROR"));
		if ((ft_atoi(arr[i]) > (ft_atoi(arr[i + 1]))))
		{
			return (1); // not sorted
		}
		i++;
	}
	return (-1); // sorted allready
}
int	error_check(char **arr)
{
	if (isdigitasci(arr + 1) < 0)
		return (ft_printf("ERROR1\n"), 1);
	if (duplicate_check(arr) < 0)
		return (ft_printf("ERROR2\n"), 1);
	if (allready_sorted(arr) < 0)
		return (ft_printf("ERROR3\n"), 1);
	return (0);
}
