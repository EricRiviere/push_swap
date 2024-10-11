/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/04 09:47:46 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	-move_both_cheapest: To bring both cheapest nodes to top saving movements
		- Iterates through both stacks while at least one of their cheapest nodes
		is on toprotating or reverse rotating both depending on the movement 
		recived as arg
		- Rsets both stacks index
*/

static void	move_both_cheapest(t_node **a, t_node **b,
							t_node *cheapest_node, char above_median)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		if (above_median == 'T')
			rr(a, b, true);
		else if (above_median == 'F')
			rrr(a, b, true);
	}
	set_index(*a);
	set_index(*b);
}

/*EXPLAINATION:
	- bring_to_top: To bring cheapest to top if needed (after move both cheapest)
		- Iterates through stack until cheapest is on top
		- If the cheapest is above median rotate otherwise reverse rotate
*/

void	bring_to_top(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

/*EXPLAINATION:
	-push_b_to_a: To optimize movements when pushing b node to stack a
		- Find the cheapest node
		- If both cheapest node and its target node are above median rotate both
		- Else (both CN and its TN below median) we reverse rotate both
		- Since we don't know if both are on top or just one, call the function 
		bring totop that will bring CN or its TN to top if they're not in top yet
		- With both CN & its TN on top we push CN (b) above its TN (a)
*/

static void	push_b_to_a(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		move_both_cheapest(a, b, cheapest_node, 'T');
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		move_both_cheapest(a, b, cheapest_node, 'F');
	bring_to_top(b, cheapest_node, 'b');
	bring_to_top(a, cheapest_node->target_node, 'a');
	pa(a, b, true);
}

/*EXPLAINATION:
	-min_on_top: To put the smallest node on top
		- While smallest is not on top (stack head):
		- If smallest is above median rotate a
		- Else reverse rotate a
*/

static void	smallest_on_top(t_node **a)
{
	while ((*a)->num != find_smallest(*a)->num)
	{
		if (find_smallest(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

/*EXPLAINATION:
	-sort_stack: To sort stack with more than 3 nodes
		- Get the stack length
		- While we have more than 3 nodes pushes nodes to b
		- Then aplies the basic sort_three to sort remaining 3 nodes
		- While there is nodes in b, it updates al nodes
			- This will set: indexes, target nodes, cost & cheapest
		- And then push a node from b to a in the most efficent way by
		rotating both stacks if neigther the cheapes node or its target
		is on top, and rotating just one stack if needed
		- Then it resets stack a indexes to call smallest on top function
		that verify if the smallest node is on top and optimizes moves
		to bring it to the top if necessary
*/
void	sort_stack(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3)
		pb(b, a, true);
	if (len_a-- > 3)
		pb(b, a, true);
	while (len_a-- > 3)
		pb(b, a, true);
	sort_three(a);
	while (*b)
	{
		update_nodes(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	smallest_on_top(a);
}
