/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:47 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*EXPLAINATION:
	-free_arr: To free argv created if we recieve only 1 argument with all numbers
		- Check if the arr is empty if so return
		- Iterates through the array and free every string
		- Free the array of strings
*/

void	free_arr(char *argv[])
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

/*EXPLAINATION:
	-free_stack: To free a stack
		- Create pointers to iterate and swap nodes
		- Check if stack is empty if so return
		- Iterate through stack saving its next connection to iterate
		and freeing each node
		- Point the stack head pointer to NULL
*/

void	free_stack(node	**stack)
{
	node	*tmp;
	node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/*EXPLAINATION:
	-error_free: To free stack, free argv and manage errors
		- Free the stack
		- Free the argv array
		- Write on error standard output
		- Exit program
*/

void	error_free(node **a, char *argv[], bool free_argv)
{
	free_stack(a);
	if (free_argv)
		free_arr(argv);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*EXPLAINATION:
	-syntax_error: to verify if numbers passed through argv are correct
		- Check if 1st letter is either +/-/number (if not ret error)
		- Check if 1st letter is either +/- and second is a number (if not err)
		- Iterates the rest of the string (number) and checks if every char
		is a number (if not returns error)
		- If everything is OK return NO ERROR
*/

int	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[i++] >= '0' && str[i++] <= '9'))
		return (1);
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

/*EXPLAINATION:
	-repetition_error: to check if there is a repeated number
		- If stack is empty returns NO ERROR
		- Iterates through stack and if number = any num in stack a returns err
		- If not returns NO ERROR
*/

int	repetition_error(node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->num == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}


