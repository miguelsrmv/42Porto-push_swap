/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:40:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/31 11:22:44 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stddef.h>

typedef struct s_list
{
	int				value;
	int				sorted;
	int				binary_value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_isdigit(char c);
long	ft_atol(char *argument);
int		check_arg_validity(char *argument, long value);
int		create_linked_list(char **argv, t_list **starting_node);
int		check_duplicates(t_list *starting_node);
int		main(int argc, char **argv);
t_list	*ft_lstnew(void *value, size_t value_size);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfirst(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list *node);
void	print_list(t_list *starting_node);
void	print_list_order(t_list *starting_node);
void	print_list_order_organized(t_list *starting_node);
void	pseudo_sort(t_list **starting_node, int list_length);
t_list	*get_min_from_list(t_list *starting_node, int list_length);
int		int_to_binary(int number);
void	sort_list(t_list **starting_node, int length);
int		elem_index(t_list *last_node, int length, int bit_slot);
void	pb(t_list **current_node, t_list *buffer_node, int *rotate_back);
void	pa(t_list **starting_node, t_list *buffer_node, int *rotate_back);
void	ra(t_list **starting_node);

#endif