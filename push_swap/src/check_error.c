/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:07 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 12:51:36 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(Node **stack_a)
{
	Node	*current;

	current = *stack_a;

	if(!current)
		return(1);
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		else
			current = current->next;
	}
	return (1);
}

int	is_int(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Number introduced not an int\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
