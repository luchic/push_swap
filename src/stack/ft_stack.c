/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:44:21 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 14:52:38 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft.h"
#include <stdlib.h>

static t_dlist	*ft_new_node(int value)
{
	t_dlist	*node;

	node = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static t_dlist	*ft_add_front(t_dlist *head, int value)
{
	t_dlist	*new_node;

	new_node = ft_new_node(value);
	if (!new_node)
		return (NULL);
	new_node->next = head;
	if (head)
		head->prev = new_node;
	return (new_node);
}

static t_dlist	*ft_setup_dlist(int *array, size_t len)
{
	t_dlist	*head;
	t_dlist	*new_head;
	size_t	i;

	head = NULL;
	while (len--)
	{
		new_head = ft_add_front(head, array[len]);
		if (!new_head)
		{
			ft_free_dlist(head);
			return (NULL);
		}
		head = new_head;
	}
	return (head);
}

t_stack	*ft_init_stack(int *array, size_t len)
{
	t_stack	*stack;
	t_dlist	*list;
	int		size;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (len == 0 || array == NULL)
		return (stack->size = 0, stack->bottom = NULL, stack);
	list = ft_setup_dlist(array, len);
	if (!list)
		return (free(stack), NULL);
	stack->top = list;
	size = 0;
	while (list->next)
	{
		list = list->next;
		size++;
	}
	stack->bottom = list;
	stack->size = size + 1;
	return (stack);
}
