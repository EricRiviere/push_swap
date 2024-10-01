/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	-set_index: To set node index and update above_median property
		- Create i & median to register index and relative position
		- If the stack is empty return NULL
		- median will be stack length divided by 2
		- Iterate through stack to set index and update above median property
*/
void	set_index(node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/*EXPLAINATION:
	-set_target_nodes: To set a target node from a in every node in b
		The target node will be the closest value in a that is greater than the value in b
		- Create a pointer to iterate through stack a (current_a)
		- Create a pointer to a target node that we'll update (almost) every iteration
		- Create an int to temp save the bigger closes value to b value from a
		- 1rst while loop: Iterates through every node in stack b
		- Set the target node to NULL for every iteration
		- Set temporary target value to INT_MAX (to iterate through stack a)
		- Reset current_a pointer to stack a head to iterate through all stack a in every
		  node of stack b
		- 2nd while loop: Iterates through stack a and updates target node if fits conditions
		- while iterating through stack a, if we find a node in a which number is bigger than
		  current b node number & smaller (closer) than temp_target_value, we update target
		  node
		- Otherwise, we jump to the next node (current_a = current_a->next)
		- If we finish iterating through stack a and we didn't find a BIGGER && CLOSER value
		  (means b node number is the highest) its target node will be the smallest in a)
		  *In this case target_node is not updated this is why its important to init as NULL*
		- Else (means we found and updated target_node), b node target node equals target_node
		- Jump to the next node on b to keep iterating (b = b->next)
*/

static void	set_target_nodes(node *a, node *b)
{
	node	*current_a;
	node	*target_node;
	int	temp_target_value;

	while (b)
	{
		target_node = NULL;
		temp_target_value = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < temp_target_value)
			{
				temp_target_value = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (temp_target_value == INT_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*EXPLAINATION:
	-set_cost: To set the cost of pushing node b to a above its target node
		Te cost of pushing = relative position of b node (to median) + "" its target node
		- Create variables to stack a & stack b length
		- Iterate through stack b to:
		-1: Set b push cost (initialize with its index && if its not avobe median the cost
		will be stack b length - b index
		-2: Sum b target node cost (same way if above median cost = index, otherwise cost =
		target stack len (len_a) - b target node -from a- index)
		- Jump to next node (b = b->next)
*/

static void	set_cost(node *a, node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!b->above_median)
			b->push_cost = len_b - b->index;
		if (!b->target_node->above_median)
			b->push_cost += len_a - b->target_node->index;
		else
			b->push_cost += b->target_node->index;
		b = b->next;
	}	
}

/*EXPLAINATION:
	-set_cheapest: To set the node property cheapest to "true" if its push_cost is the
	lowest among all nodes
		- Create a pointer to the cheapest node and to stack b head
		- Check if b is empty
		- Iterate trhough b using current_b pointer to set cheapest_node pointer
		to the node with lowest push_cost
		- Reset current_b to stack b head to iterate through it and set all nodes
		cheapest property to false
		- Set cheapest_node cheapest property yo true
*/
static void	set_cheapest(node *b)
{
	node	*cheapest_node;
	node	*current_b;

	if (b == NULL)
		return ;
	cheapest_node = b;
	current_b = b;
	while (current_b)
	{
		if (current_b->cost < cheapest_node->cost)
			cheapest_node = current_b;
		current_b = current_b->next;
	}
	current_b = b;
	while (current_b)
	{
		current_b->cheapest = false;
		current_b = current_b->next;
	}
	cheapest_node->cheapest = true;
}

/*EXPLAINATION:
	-update_nodes: To update all nodes after every push movement
		- Resets both stacks index
		- Resets all b targets nodes (from a stack)
		- Resets all b nodes push cost
		- Reset the cheapest node in b
*/

void	update_nodes(node **a, node **b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}




