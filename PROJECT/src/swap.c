/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:23:39 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/04 09:55:55 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* EXPLAINATION:
	-Get the stack len to protect de swap if not possible
	-Create pointers to first and second node to work from there
		-First points to stack head node
		-Second points to stack second node
	-1:change the next conection from first node to point to second next
	-2:check if there is a 3rd node not to lose its prev connection
		-If there is a 3rd node we chage its prev con. to point to first node 
		(instead of second node)
	-3:First prev con. now points to second
	-4:Second next con. now points to first
	-5:Second prev con. now points to NULL
	-6:Move head to second
*/
static void	swap(t_node **head)
{
	int		len;
	t_node	*first;
	t_node	*second;

	len = stack_len(*head);
	if (*head == NULL || len == 1)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*head = second;
}

void	sa(t_node **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_node **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
