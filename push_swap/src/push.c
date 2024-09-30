/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:16:27 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 12:30:25 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void push_b(Node **stack_a, Node **stack_b, int print)
{
    if (!*stack_a)
    return ;
    Node *push_head;

    push_head = *stack_a;
    *stack_a = push_head->next;
    push_head->next = *stack_b;
    *stack_b = push_head;
	if (print)
		ft_printf("pb\n");
}
void push_a(Node **stack_a, Node **stack_b, int print)
{
    if (!*stack_b)
        return ;
    Node *push_head;

    push_head = *stack_b;
    *stack_b = push_head->next;
    push_head->next = *stack_a;
    *stack_a = push_head;
	if (print)
		ft_printf("pa\n");
}
