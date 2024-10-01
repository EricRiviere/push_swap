/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* EXPLAINATION:
	- We need to push a node from 1 stack (src) to another (dest)
	-1: Create a pointer to the pushed node, src_first & dest_first (readability)
	-2: We point src_first & dest_first to the stack heads
	-3: Check if we have a node to push (if not return)
	-4: Now that we're shure that we have a node to push, the pointer (pushed_node
	    that we created points to our src stack head
	-5: We move the head of src to the next node
	*IMPORTANT* src_first & dest_first is NOT the same as *src and *dest (both 
	start at the head of each stack and then are modified)
	-6: If we don't have src_first (meaning we just have 1 node in src stack),
	    point prev connection to NULL (first prev and last next will always be NULL)
	-7: Since the pushed node is on top of dest stack, we point its prev to NULL
	-8: If dest stack is empty, its head will be pushed node and its prev NULL
	-9: Else, the next con. of pushed node will be dest head
	-10: The prev con. of pushed node next node will point to pushed node
	-11: Move the head of dest to pushed node
*/

static void	push(node **dest, node **src)
{
	node	*pushed_node;
	node	*src_first;
	node	*dest_first;

	src_first = *src;
	dest_first = *dest;
	if (src_first == NULL)
		return ;
	pushed_node = src_first;
	*src = src_first->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (dest_first == NULL)
	{
		*dest = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = *dest_first;
		pushed_node->next->prev = pushed_node;
		*dest = pushed_node;
	}
}

void	push_a(node **a, node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	push_b(node **b, node **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}


