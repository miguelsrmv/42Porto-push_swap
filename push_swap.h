/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:40:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/27 18:17:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	int				sorted;
	int				binary_value;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(char c);
long	ft_atol(char *argument);
int		check_arg_validity(char *argument, long value);
int		create_linked_list(char **argv, t_list **starting_node);
int		check_duplicates(t_list *starting_node);
int		main(int argc, char **argv);
t_list	*ft_lstnew(void *value);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *node);
void	print_list(t_list *starting_node);
void	print_list_order(t_list *starting_node);
void	pseudo_sort(t_list **starting_node, int list_length);
t_list	*get_min_from_list(t_list *starting_node, int list_length);

#endif