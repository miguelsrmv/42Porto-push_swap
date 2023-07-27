/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:40:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/27 11:17:08 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				value;
	long			final_value;
	int				binary_value;
	struct s_list	*next;
}	t_list;

int ft_atol(char *argument);
int	create_linked_list(char **argv, t_list **starting_node);
int check_duplicates(t_list *starting_node);
int	main(int argc, char **argv);
t_list	*ft_lstnew(int *value);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *node);
void print_list(t_list *starting_node);

#endif