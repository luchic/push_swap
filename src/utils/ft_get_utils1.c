/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:50:56 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 16:20:14 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack.h"

t_dlist	*ft_get_nnode(t_stack *stack, int n)
{
	t_dlist	*current;
	int		i;

	if (!stack || stack->size == 0 || n < 0 || n >= stack->size)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current && i < n)
	{
		current = current->next;
		i++;
	}
	return (current);
}

int	ft_get_nel(t_stack *stack, int n)
{
	t_dlist	*cur;

	cur = ft_get_nnode(stack, n);
	if (!cur)
		return (-1);
	return (cur->value);
}

int	ft_get_bottom_nel(t_stack *stack, int n)
{
	t_dlist	*cur;
	int		size;

	if (!stack || stack->size == 0 || n < 0 || n >= stack->size)
		return (-1);
	size = stack->size - 1 - n;
	cur = ft_get_nnode(stack, size);
	if (!cur)
		return (-1);
	return (cur->value);
}

int	ft_get_size_chunk(const t_chunks *chunks, t_type type)
{
	int	size_chunk;

	if (type == MIN)
		size_chunk = chunks->min.max - chunks->min.min + 1;
	else if (type == MID)
		size_chunk = chunks->mid.max - chunks->mid.min + 1;
	else
		size_chunk = chunks->max.max - chunks->max.min + 1;
	return (size_chunk);
}

int	ft_get_size_all_chunks(const t_chunks *chunks)
{
	int	size;

	size = ft_get_size_chunk(chunks, MIN);
	size += ft_get_size_chunk(chunks, MID);
	size += ft_get_size_chunk(chunks, MAX);
	return (size);
}
