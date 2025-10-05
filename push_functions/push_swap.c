/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:04:44 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/03 15:32:35 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

// real main

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				i;

	stack_a = NULL;
	stack_b = NULL;
	i = error_check(argv, argc - 1);
	if (i > 0) // i == 1 is error
		return (0);
	*stack_a = stackcreate(argv);
	*stack_b = stackcreate(NULL);
	printStack(stack_a);
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