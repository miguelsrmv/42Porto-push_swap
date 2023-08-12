/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:40:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/12 15:56:25 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

typedef struct s_inst
{
	char			*command;
	struct s_inst	*next;
}	t_inst;

// Bonus.c
int			main(int argc, char **argv);

// Validate_create_linked_list.c
int			ft_isdigit(char c);
long		ft_atol(char *argument);
int			check_args(char **argv);
int			check_duplicates(t_list *starting_node);
int			create_linked_list(char **argv, t_list **starting_node);

// Process_stacks.c
void		create_stacks(t_list **starting_node, t_ptr **stack_a,
				t_ptr **stack_b, int length);
void		reset_stacks(t_ptr **stack_a, t_ptr **stack_b,
				int length_a, int length_b);
void		reset_node(t_list **node, t_ptr **stack, int length);

// Linked_list_func.c
t_list		*ft_lstnew(void *value);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list *node);
void		free_allocs(t_ptr **stack_a, t_ptr **stack_b);

// Sort.c
int			check_sorted(t_ptr **stack_a);
void		sort(t_ptr **stack_a, t_ptr **stack_b, int argc);
void		small_sort_2(t_ptr **stack);
void		small_sort_3(t_ptr **stack);
void		big_sort(t_ptr **stack_a, t_ptr **stack_b);

// Moves.c
/// Moves_rotate.c
void		rotate_stack(t_ptr **stack);
void		rotate_both(t_ptr **stack_a, t_ptr **stack_b);
void		reverse_rotate_stack(t_ptr **stack);
void		reverse_rotate_both(t_ptr **stack_a, t_ptr **stack_b);

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

// Helper_functions.c
void		print_list_order_organized(t_ptr *starting_node);
void		print_instruction(char *instruction, char stack);	
void		print_stack_data(t_ptr *stack);
void		test_input(t_ptr **stack_a, t_ptr **stack_b);
void		execute_input(char *input, t_ptr **stack_a, t_ptr **stack_b);

#endif