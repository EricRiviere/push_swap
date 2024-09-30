/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:17:31 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:08:06 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*find_smallest(Node **stack_a)
{
	int		min_value;
	Node	*min_node;
	Node	*current;

	min_value = INT_MAX;
	current = *stack_a;
	while (current)
	{
		if (current->content < min_value)
		{
			min_value = current->content;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

Node	*find_prev(Node *stack_a)
{
	while (stack_a->next->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

Node	*find_last(Node *stack_a)
{
    while (stack_a)
    {
        if (stack_a->next == NULL)
            return (stack_a);
        stack_a = stack_a->next;
    }
    return (stack_a);
}

Node	*init_node(Node **stack_a, int value)
{
    Node *new_node;
    Node *last_node;
    new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return (NULL);
    new_node->content = value;
    new_node->next = NULL;
    if (*stack_a == NULL)
    {
        *stack_a = new_node;
        return (new_node);
    }
    last_node = find_last(*stack_a);
    if (last_node)
        last_node->next = new_node;
    return (new_node);
}

long	ft_atol(char *str)
{
	long nbl;
	int	sign;

	nbl = 0;
	sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbl = nbl * 10 + *str - '0';
		str++;
	}
	return (nbl * sign);
}
