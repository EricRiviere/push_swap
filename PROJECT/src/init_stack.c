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
	-replicate_argv: To use original ft_split and replicate argv
	We need this function to manage the case that we recive just 1 argument with
	all numbers in it.
	If we split the argument directly we'll lack of the argv[0] wich refers to the
	program name.
	This function splits argv[1] and allocates space for an extra space to then
	copiy every string in the new array.
	Doing so we end up with: argv[0] = 0, argv[1] = first number and so on.
*/

char	**replicate_argv(char const *s, char c)
{
	char	**arr;
	char	**new_arr;
	size_t	i;
	size_t	word_count;

	arr = ft_split(s, c);
	if (!arr)
		return (NULL);
	word_count = 0;
	while (arr[word_count])
		word_count++;
	new_arr = malloc(sizeof(char *) * (word_count + 2));
	if (!new_arr)
		return (NULL);
	new_arr[0] = malloc(sizeof(char));
	if (!new_arr[0])
		return (NULL);
	new_arr[0][0] = 0;
	i = -1;
	while (arr[++i])
		new_arr[i + 1] = arr[i];
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}

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

void	init_stack(node **a, char *argv[], bool free_argv)
{
	int	i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_free(a, argv, free_argv);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_free(a, argv, free_argv);
		if (repetition_error(*a, (int)num))
			error_free(a, argv, free_argv);
		append_node(a, (int)num);
		i++;
	}
	if (free_argv)
		free_arr(argv);
}




