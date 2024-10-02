/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:17:53 by eriviere          #+#    #+#             */
/*   Updated: 2024/09/30 13:05:37 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
    #define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int		num;
	int		index;
	int		push_cost;
	bool		above_median;
	bool		cheapest;
		
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
} node;

//Initialization functions:
long    ft_atol(char *str);
void    init_stack(node **a, char *argv[], bool free_argv);
void    append_node(node **stack, int num);

//Stack manipulation functions:
void    pa(node **a, node **b, bool print);
void    pb(node **b, node **a, bool print);
void    sa(node **a, bool print);
void    sb(node **b, bool print);
void    ss(node **a, node **b, bool print);
void    ra(node **a, bool print);
void    rb(node **b, bool print);
void    rr(node **a, node **b, bool print);
void    rra(node **a, bool print);
void    rrb(node **b, bool print);
void    rrr(node **a, node **b, bool print);
void    bring_to_top(node **stack, node *top_node, char stack_name);
void    update_nodes(node *a, node *b);

//Utility functions:
node    *find_last(node *stack);
node    *find_smallest(node *stack);
bool    is_sorted(node *stack);
int     stack_len(node *stack);
void    set_index(node *stack);
node    *find_cheapest(node *stack);
char	**replicate_argv(char const *s, char c);

//Error management:
void	free_arr(char *argv[]);
void	free_stack(node	**stack);
void	error_free(node **a, char *argv[], bool free_argv);
int	syntax_error(char *str);
int	repetition_error(node *a, int nbr);

//Sorting functions:
void    sort_three(node **a);
void    sort_stack(node **a, node **b);
#endif
