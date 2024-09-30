/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:16:45 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 12:37:23 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void rotate_b(Node **stack_b, int print)
{
    Node	*first;
    Node	*last;

    first = *stack_b;
    last = find_last(*stack_b);
    *stack_b = first->next;
    last->next = first;
    first->next = NULL;
	if (print)
		ft_printf("rb\n");

}

void reverse_rotate_b(Node **stack_b, int print)
{
    Node	*first;
    Node	*last;
	Node	*last_prev;

    first = *stack_b;
    last = find_last(*stack_b);
	last_prev = find_prev(*stack_b);

    *stack_b = last;
    last->next = first;
    last_prev->next = NULL;
	if (print)
		ft_printf("rrb\n");
}


void rotate_a(Node **stack_a, int print)
{
    Node *first;
    Node *last;

    first = *stack_a;
    last = find_last(*stack_a);
    *stack_a = first->next;
    last->next = first;
    first->next = NULL;
	if (print)
		ft_printf("ra\n");
}

void reverse_rotate_a(Node **stack_a, int print)
{
    Node	*first;
    Node	*last;
	Node	*last_prev;

    first = *stack_a;
    last = find_last(*stack_a);
	last_prev = find_prev(*stack_a);

    *stack_a = last;
    last->next = first;
    last_prev->next = NULL;
	if (print)
		ft_printf("rra\n");
}

