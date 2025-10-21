/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:04:44 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/21 16:37:41 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

// real main

int	main(int argc, char **argv)
{
	t_stack_node	**a;
	t_stack_node	**b;
	bool			i;
	int				digits[argc];

	a = NULL;
	b = NULL;
	i = error_check(argv, argc - 1);
	if (i > 0) // i == 1 is error
		return (1);
	i = mapping(argv, lenofstring(argv), digits); // mapped 0,1,2,3,4...
	if (i > 0)                                    // i == 1 is error
		return (1);
	if (argc < 7)
		return (smalldigits(digits, argc - 1), 1);
	// argv = arrtobin(digits, argv + 1); // mapped to Binaer
	*a = stackcreate(digits, a);
	*b = stackcreate(NULL, b);
	printStack(*a);
	return (0);
}

// test main

// int	main(void)
// {
// 	char **string;
// 	int i;
// 	t_stack_node *stack_a;

// 	string = malloc(sizeof(char *) * 4);
// 	if (!string)
// 		return (1);
// 	i = 0;
// 	while (i < 3)
// 	{
// 		string[i] = "i";
// 		i++;
// 	}
// 	string[0] = "nop";
// 	string[2] = "bipp";
// 	string[i] = NULL;
// 	i = 0;
// 	while (i < 3)
// 	{
// 		printf("%s", string[i]);
// 		i++;
// 	}
// 	*stack_a = stackcreate(string);
// 	printStack(stack_a);
// }