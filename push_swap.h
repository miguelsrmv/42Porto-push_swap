/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:40:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 11:25:56 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	int				position;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct t_ptr
{
	char			name;
	t_list			*next;
}	t_ptr;

// Main.c
int		main(int argc, char **argv);

// Arg_value_checker.c
int		ft_isdigit(char c);
long	ft_atol(char *argument);
int		check_arg_validity(char *argument, long value);
int		check_duplicates(t_list *starting_node);

// Process_linked_list.c
int		create_linked_list(char **argv, t_list **starting_node);
void	create_stacks(t_list **starting_node, t_ptr **stack_a, t_ptr **stack_b);

// LInked_list_func.c
t_list	*ft_lstnew(void *value);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfirst(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list *node);

// Helper_functions.c
void	print_list_order_organized(t_list *starting_node, char c, int length);
char	*print_tab_calc(t_list *prev);
void	print_instruction(char *instruction, char stack);	

// Sort.c
void	sort_list(t_list **starting_node, int length);
int		is_a_sorted(t_list *current_node, t_list *buffer_node);

// Moves.c



void	rotate_stack(t_ptr **stack);
void	rotate_both(t_ptr **stack_a, t_ptr **stack_b);

void	reverse_rotate_stack(t_ptr **stack);
void	reverse_rotate_both(t_ptr **stack_a, t_ptr **stack_b);

#endif