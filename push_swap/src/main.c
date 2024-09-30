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


int main(int argc, char *argv[])
{
	Node	*stack_a;
	Node	*stack_b;
	Node	*new_node;
	//Node	*current;
	int		count;

	count = 1;
	stack_a = NULL;
	stack_b = NULL;

	if(argc < 2)
	{
		ft_putstr_fd("Introduce arguments to sort numbers\n", 2);
		return (1);
	}
	while (argv[count])
	{
		int	num = ft_atoi(argv[count]);
		new_node = init_node(&stack_a, num);
		count++;
	}
	if (argc == 4)
		sort_three(&stack_a);
	/*
	current = stack_a;
	while (current)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	*/
        return (0);
}
