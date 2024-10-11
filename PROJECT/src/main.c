/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/04 10:17:55 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	-main: To initiate program
		- Create empty nodes for both stacks (a, b)
		- Protect the case in wich no argument or empty argument is provided
		- If the number of arguments is 2 (aka we are recivieng a string with
		all arguments) we use the function replicate_argv to simulate argv
		- Then we init the stack with the flag (free_arg in init stack function) 
		to free simulated argv if argc = 2 (if needed else all remain the same)
		- Check if the stack is already sorted (if so we free the stack)
		- If the stack is not sorted:
			- If we have 2 nodes we swap
			- If we have 3 we apply base sort_three function
			- Else we call sort_stack function that trigers all the optimization
			moves to sort
		- Free the stack
*/

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_putstr_fd("Error\n", 2);
	else if (argc == 2)
		argv = replicate_argv(argv[1], ' ');
	init_stack(&a, argv + 1, argc == 2);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
