/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:40:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/09 16:33:44 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	int				position;
	int				rev_position;
	int				target;
	int				rev_target;
	int				cost;
	char			pattern;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_ptr
{
	char			name;
	int				length;
	t_list			*next;
}	t_ptr;

typedef struct s_cost
{
	int		a_up_b_up;
	int		a_down_b_down;
	int		a_up_b_down;
	int		a_down_b_up;
	char	course;
}	t_cost;

typedef struct s_instruct
{
	int		a;
	int		b;
	int		both;
}	t_instruct;

// Main.c
int			main(int argc, char **argv);

// Arg_value_checker.c
int			ft_isdigit(char c);
long		ft_atol(char *argument);
int			check_arg_validity(char *argument, long value);
int			check_duplicates(t_list *starting_node);

// Process_linked_list.c
int			create_linked_list(char **argv, t_list **starting_node);
void		create_stacks(t_list **starting_node, t_ptr **stack_a,
				t_ptr **stack_b, int length);
void		print_instruction(char *instruction, char stack);

// LInked_list_func.c
t_list		*ft_lstnew(void *value);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list *node);

// Helper_functions.c
void		print_list_order_organized(t_ptr *starting_node);
void		print_instruction(char *instruction, char stack);	
void		print_stack_data(t_ptr *stack);
void		test_input(t_ptr **stack_a, t_ptr **stack_b);
void		execute_input(char *input, t_ptr **stack_a, t_ptr **stack_b);

// Sort.c
void		reset_stacks(t_ptr **stack_a, t_ptr **stack_b,
				int length_a, int length_b);
void		reset_node(t_list **node, t_ptr **stack, int length);
int			check_sorted(t_ptr **stack_a, t_ptr **stack_b);
void		sort(t_ptr **stack_a, t_ptr **stack_b);
void		correct_pointer(t_ptr **stack_a);
t_instruct	*create_instruction(t_instruct *instruction);

// Sort_2.c
void		small_sort_3(t_ptr **stack);
void		find_position_b(t_ptr **stack_a, t_ptr **stack_b, int length_a);
void		find_position_a(t_ptr **stack_a, t_ptr **stack_b, int length_a);
void		max_targets(t_list **node, t_ptr **stack_a);
void		min_targets(t_list **node, t_ptr **stack_b);
void		correct_targets(t_list **node, int length);
void		rotate_back_pattern(t_ptr **stack_a, t_ptr **stack_b, int length);
void		rotate_back_and_push(t_ptr **stack_a, t_ptr **stack_b);
void		final_rotate_back(t_ptr **stack_a);


/// Calculate_cost.c
int			min_cost(int a, int b, int c, int d);
int			max_val(int a, int b);
int			movement_cost(t_ptr **stack_a, t_ptr **stack_b, int length_a);
void		calculate_cost(t_list **stack_a, t_cost *cost);
t_ptr		*get_min_cost_node(t_ptr *stack_a);

/// Calculate_move.c
void		rotate_pattern(t_ptr **node, t_ptr **stack_a, t_ptr **stack_b);
void		calc_rotate_a_up_b_up(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);
void		calc_rotate_a_down_b_down(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);
void		calc_rotate_a_up_b_down(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);
void		calc_rotate_a_down_b_up(t_ptr **node, t_ptr **stack_a,
				t_ptr **stack_b);

// Moves.c
/// Moves_rotate.c
void		rotate_stack(t_ptr **stack);
void		rotate_both(t_ptr **stack_a, t_ptr **stack_b);
void		reverse_rotate_stack(t_ptr **stack);
void		reverse_rotate_both(t_ptr **stack_a, t_ptr **stack_b);
void		rotate(t_instruct **rotate_instruct, t_ptr **stack_a,
				t_ptr **stack_b);
/// Moves_swap.c
void		swap_stack(t_ptr **stack);
void		swap_both(t_ptr **stack_a, t_ptr **stack_b);
void		swap(int *a, int *b);
/// Moves_push.c
void		push_to_0(t_ptr **stack_from, t_ptr **stack_to);
void		push_to_1(t_ptr **stack_from, t_ptr **stack_to);
void		push_from_1(t_ptr **stack_from, t_ptr **stack_to);
void		push_to_x(t_ptr **stack_from, t_ptr **stack_to);
void		push(t_ptr **stack_from, t_ptr **stack_to);

#endif