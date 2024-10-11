/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:17:53 by eriviere          #+#    #+#             */
/*   Updated: 2024/10/04 09:53:06 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				num;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;		
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}	t_node;

//Initialization functions:
long	ft_atol(char *str);
void	init_stack(t_node **a, char *argv[], bool free_argv);
void	append_node(t_node **stack, int num);

//Stack manipulation functions:
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	bring_to_top(t_node **stack, t_node *top_node, char stack_name);
void	update_nodes(t_node *a, t_node *b);

//Utility functions:
t_node	*find_last(t_node *stack);
t_node	*find_smallest(t_node *stack);
bool	is_sorted(t_node *stack);
int		stack_len(t_node *stack);
void	set_index(t_node *stack);
t_node	*find_cheapest(t_node *stack);
char	**replicate_argv(char const *s, char c);

//Error management:
void	free_arr(char *argv[]);
void	free_stack(t_node	**stack);
void	error_free(t_node **a, char *argv[], bool free_argv);
int		syntax_error(char *str);
int		repetition_error(t_node *a, int nbr);

//Sorting functions:
void	sort_three(t_node **a);
void	sort_stack(t_node **a, t_node **b);
#endif
