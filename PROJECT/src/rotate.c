/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/04 09:48:43 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*EXPLAINATION:
	- Create a pointer to the first and last node of the stack
	- Establish length of stack to asure rotate operation can be done
	- initialize pointers and protect rotate operation
	-1: Move stack head to second node (first->next)
	-2: Set second node prev as NULL
	-3: Set first node next to NULL (since now it will be the last node)
	-4: "" last node next as first (last node is no longer last node)
	-5: "" first node (now last) prev as last
*/
static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;
	int		len;

	first = *stack;
	len = stack_len(*stack);
	if (first == NULL || len == 1)
		return ;
	last = find_last(*stack);
	*stack = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void	ra(t_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
