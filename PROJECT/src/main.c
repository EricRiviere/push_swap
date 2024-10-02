/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	node	*a;
	node	*b;
	
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
	/*
	node *current_node = a;
	while (current_node)
	{
		ft_printf("%d\n", current_node->num);
		current_node = current_node->next;
	}
	*/
	free_stack(&a);
	return (0);
}
