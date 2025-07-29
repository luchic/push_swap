/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:44:21 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/29 21:34:57 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft.h"

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

static t_dlist	*ft_setup_dlist(int *array, size_t len)
{
	t_dlist	*head;
	t_dlist	*current;
	size_t	i;

	return (head);
}

static t_dlist	*ft_setup_container(char **data, size_t len)
{
	size_t	i;
	int		*array;
	t_dlist	*lst;

	i = -1;
	array = (int *)ft_calloc(len, sizeof(int));
	if (!array)
		return (NULL);
	while (++i < len)
		array[i] = ft_atoi(data[i]);
	lst = ft_setup_dlist(array, len);
	free(array);
	return (lst);
}

t_stack	*ft_init_stack(char **data, size_t len)
{
	t_stack	*stack;
	t_dlist	*list;
	int		size;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (len == 0 || data == NULL)
		return (stack->size = 0, stack->bottom = NULL, stack->bottom = NULL,
			stack);
	list = ft_setup_container(size, data);
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
