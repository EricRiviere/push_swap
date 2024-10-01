/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	- ft_atol: To convert string from argv to long (we need to accept numbers
		   longer than an int to then check if its over int limits)
		- Create variables res (for the result number), sign (to set the 
		  number as negative if needed) and i to iterate throught string
		- Iterate through str to ignore spaces and tabs
		- Iterate through str to manage sign (negative or positive)
		- If negative we change sign to -1
		- Iterate through str while its a number
		- If its a number we convert it to int by:
			- multiplying res by 10 and adding the value of str in that
			  position - 0 value
		- Return res multiplied by sign (if its positive stays the same
		  otherwise it changes its value to negative)
*/

long	ft_atol(char *str)
{
	long	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

/*EXPLAINATION:
	-init_stack: To initialize stack from argv values (these give num to nodes)
		- Create i & num variables to iterate through argv and give value to 
		  num variable inside the node
		- Initialize i at 1 to skip the program name (argv[0])
		- Iterate through argv converting it to long
		- Call to append_node to create a new_node with num value
*/

void	init_stack(node **stack, char *argv[])
{
	int	i;
	long	num;

	i = 1;
	while (argv[i])
	{
		//Falta revisar errores antes de iniciar stack
		//sintaxis, limites int, repeticion
		num = ft_atol(argv[i]);
		append_node(&stack, (int)num);
		i++;
	}
}




