/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:54:16 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:06:13 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*sort_stack(Node **stack_a, int count)
{
	if (count == 2)
		swap_a(stack_a, 1);
	if (count == 3)
		sort_three(stack_a);
	return (*stack_a);
}

void	sort_three(Node **stack_a)
{
	Node	*current;
	Node	*max_node;
	int		max_value;

	current = *stack_a;
	max_value = INT_MIN;

	while (current)
	{
		if (current->content > max_value)
		{
			max_value = current->content;
			max_node = current;
		}
		current = current->next;
	}
	if (max_node == *stack_a)
		rotate_a(stack_a, 1);
	else if (max_node == (*stack_a)->next)
			reverse_rotate_a(stack_a, 1);
	if((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a, 1);
}
