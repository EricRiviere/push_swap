/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	-stack_len: To find stack length
		- Create a node to iterate stack;
		- Create len variable to count stack length
		- If the stack is empty return 0 (0 length)
		- Else iterate until finding stack end (NULL) and increase len
		- Return len
*/
int	stack_len(node **stack)
{
	node *current_node;
	int	len;

	len = 0;
	current_node = *stack;
	if (current_node == NULL)
		return (0);
	while (current_node != NULL)
	{
		current_node = current_node->next;
		len++;
	}
	return (len);
}

/*EXPLAINATION:
	-find_last: To find the last node of the stack
		- Create a pointer to the last node
		- If the stack is empty, return NULL
		- Else, iterate throught the stack until reaching the last node
		  (last node next is NULL)
		- Return the last node
*/

node	*find_last(node *stack)
{
	node	*last;

	last = stack;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

/*EXPLAINATION:
	-append_node: To create and add a new node at the end of the stack with var num
		- Create a pointer to the new node and last node
		- If the stack is empty return
		- Allocate memory for new node and protect the allocation
		- Set node number, and next con. to NULL (we add the node at the end)
		- If the stack is empty, the head will be new node and prev NULL
		- Else, set new_node as last_node next & last_node as new_node prev
*/
void	append_node(node **stack, int num)
{
	node	*new_node;
	node	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->num = num;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

/*EXPLAINATION:
	-find_smallest: To find node with smallest var num
		- Create pointer to current_node to iterate  and smallest node to return
		- If the stack is empty return NULL
		- Initialize smallest as current node (to give smallest an initial num)
		- Iterate through stack and update smallest if its < than c_n num
		- Return smallest node
*/

node	*find_smallest(node *stack)
{
	node	*smallest;
	node	*current_node;

	current_node = stack;
	if (current_node == NULL)
		return (NULL);
	smallest = current_node;
	while (current_node != NULL)
	{
		if (current_node->num < smallest->num)
			smallest = current_node;
		current_node = current_node->next;
	}
	return (smallest);
}

/*EXPLAINATION:
	- find_cheapest: To find the node with cheapest bool var set as true
		- Create a pointer to stack head to iterate
		- Check if the stack is empty (if so return NULL)
		- Iterate through stack until finding the node with cheapest
		  var as true
		- Return cheapest node
*/

node	*find_cheapest(node **stack)
{
	node	*current_node;

	if (*stack == NULL)
		return (NULL);
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->cheapest)
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}



