/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:26:14 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 15:55:26 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack.h"
#include "ft_utils.h"

t_pos	ft_get_position_all_chunks(t_stack *stack_a, t_stack *stack_b,
		t_chunks *chunks)
{
	int	element;
	int	size;
	int	i;
	int	is_found;

	is_found = 0;
	element = chunks->mid.min;
	size = ft_get_size_all_chunks(chunks);
	i = 0;
	while (i < size)
	{
		if (ft_get_nel(stack_b, i) == element)
		{
			is_found = 1;
			break ;
		}
		i++;
	}
	if (is_found)
		return (TOP_B);
	i = 0;
	while (i < size)
	{
		if (ft_get_nel(stack_a, i) == element)
		{
			is_found = 1;
			break ;
		}
		i++;
	}
	if (is_found)
		return (TOP_A);
	return (BOTTOM_A);
}

t_pos	ft_get_max_position(t_stack *stack_a, t_chunks *chunks)
{
	int	is_found;
	int	value;
	int	i;
	int	size;

	size = ft_get_size_chunk(chunks, MAX);
	is_found = 0;
	value = chunks->max.min;
	i = 0;
	while (i < size)
	{
		if (ft_get_nel(stack_a, i) == value)
			is_found = 1;
		i++;
	}
	if (is_found)
		return (TOP_A);
	return (BOTTOM_A);
}

t_pos	ft_get_mid_position(t_stack *stack_b, t_chunks *chunks)
{
	int	is_found;
	int	value;
	int	i;
	int	size;

	size = ft_get_size_chunk(chunks, MID);
	is_found = 0;
	value = chunks->mid.min;
	i = 0;
	while (i < size)
	{
		if (ft_get_nel(stack_b, i) == value)
			is_found = 1;
		i++;
	}
	if (is_found)
		return (TOP_B);
	return (BOTTOM_A);
}

t_pos	ft_get_position(t_stack *stack_a, t_stack *stack_b, t_chunks *chunks,
		t_type type)
{
	if (type == MAX)
		return (ft_get_max_position(stack_a, chunks));
	if (type == MID)
		return (ft_get_mid_position(stack_b, chunks));
	return (TOP_A);
}
