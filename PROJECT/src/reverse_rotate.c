/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverese_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	- Create pointers to first and last node of the stack
	- Establish length of stack to assure reverse rotate can be done
	- Initialize pointers and protect reverse rotate operation
	-1: Set the head to last node (now the first node)
	-2: Set last node's previous node's next to NULL (now the last node)
	-3: Set last node's next to old first node (now second node)
	-4: Set old first node's previous to last node
*/

static void	reverse_rotate(node **stack)
{
	node	*first;
	node	*last;
	int	len;

	first = *stack;
	len = stack_len(*stack);
	if (first == NULL || len == 1)
		return ;
	last = find_last(*stack);
	*stack = last;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
}

void	rra(node **a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(node **b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(node **a, node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
}


