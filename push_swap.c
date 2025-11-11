/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:04:44 by opaulman          #+#    #+#             */
/*   Updated: 2025/11/11 13:57:29 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	printarray(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
}
char	**split(int argc, char **argv, int **digits)
{
	char	**newargv;
	int		i;

	i = 0;
	newargv = NULL;
	if (argc < 2)
		exit(ft_printf("ERROR\n"));
	if (argc == 2)
	{
		newargv = ft_split(argv[1], ' '); // Beispiel : "123 134 1321"
		if (!newargv)
			exit(ft_printf("ERROR\n"));
		i = count_split(newargv);
	}
	else
	{
		newargv = argv + 1;
		i = argc - 1;
	}
	*digits = malloc((i + 1) * sizeof(int));
	if (!*digits)
		exit(ft_printf("ERROR\n"));
	return (newargv);
}

int	count_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				*digits;
	char			**args;
	int				size;

	a = NULL;
	b = NULL;
	args = split(argc, argv, &digits);
	if (error_check(args) == 1) // special cases
		return (1);
	size = count_split(args);
	if (mapping(args, size, digits) > 0) // mapped 0,1,2,3,4...
		return (1);
	if (size < 6)
		smalldigits(digits, size); // for 2 to 5 digits exit included
	stackcreate(digits, &a, size); // creates stack a
	algorithm(&a, &b, size);       // in radix.c
	ft_printf("\nstacka\n");
	printstack(a);
	ft_printf("stackb:\n");
	printstack(b);
	if (size == 2)
		free(args);
	free(digits);
	return (0);
}
