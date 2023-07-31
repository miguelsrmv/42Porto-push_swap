/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:49:32 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/31 16:00:58 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "push_swap.h"
#include <stdio.h>

// Create new node
t_list	*ft_lstnew(void *value, int buffer_flag)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));

	if (!node)
		return (NULL);
	node->value = *(int *)value;
	node->sorted = -1;
	node->next = NULL;
	node->prev = NULL;
	node->buffer_flag = buffer_flag;
	return (node);
}

// Returns last node of list
t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

// Returns first node of list
t_list	*ft_lstfirst(t_list *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}

// Add created node at end of list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_elem = ft_lstlast(*lst);
		new->prev = last_elem;
		last_elem->next = new;
	}
}

// Add created node at beginning of list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// Clears list
void	ft_lstclear(t_list *node)
{
	if (node->next == NULL)
	{
		free(node);
		return ;
	}
	ft_lstclear(node->next);
	free(node);
}
