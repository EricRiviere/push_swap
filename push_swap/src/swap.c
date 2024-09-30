/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:17:12 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 12:39:21 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(Node **stack_a, int print)
{
    Node *first_position;
    Node *second_position;

    first_position = *stack_a;
    second_position = first_position->next;
    first_position->next = second_position->next;
    second_position->next = first_position;
    *stack_a = second_position;
    if (print)
        ft_printf("sa\n");
}

void swap_b(Node **stack_b, int print)
{
    Node *first_position;
    Node *second_position;

    first_position = *stack_b;
    second_position = first_position->next;
    first_position->next = second_position->next;
    second_position->next = first_position;
    *stack_b = second_position;
    if (print)
        ft_printf("sb\n");
}

void ss(Node **stack_a, Node **stack_b, int print)
{
    if (stack_a && *stack_a && (*stack_a)->next) {
        swap_a(stack_a, 0);
    }
    if (stack_b && *stack_b && (*stack_b)->next) {
        swap_b(stack_b, 0);
    }
    if (print)
        ft_printf("ss\n");
}
