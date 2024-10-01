/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	-is_sorted: To verify if a stack is already sorted
		- Check if the stack is empty (if so returns NULL)
		- Iterates through all nodes on the stack and if it finds a number
		not sorted returns false, otherwise returns true
*/
bool	is_sorted(node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/*EXPLAINATION:
	-find_highest: To find and return the node with highest num on the stack
		- Creates a pointer to the higher_node and initialize it at stack head
		- Protect function in case stack is empty
		- Iterates through stack and updates highest_node if a highest num node
		is found
*/

static node	*find_highest(node *stack)
{
	node	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest_node = stack;
	while (stack != NULL)
	{
		if (stack->num > highest_node->num)
			highest_node = stack;
		stack = stack->next;
	}
	return (highest_node);
}

/*EXPLAINATION:
	- sort_three: To sort a stack with three nodes.
		- Finds the highest node
		- It it is on the stack 1st position (head) sets it at the bottom (ra)
		- Else if it is on the 2nd position sets it at the bottom (with rra)
		- Then checks if a swap is needed by comparing 1rst and 2nd node:
		If 1rst > 2nd it swaps the first 2 nodes (otherwise stack already sorted)
*/

void	sort_three(node **a)
{
	node	*highest_node;

	if (*a == NULL)
		return ;
	highest_node = find_highest(*a);
	if (highest_node == *a)
		ra(a, true);
	else if (highest_node == (*a)->next)
		rra(a, true);
	if ((*a)->num > (*a)->next->num)
		sa(a, true);
}




