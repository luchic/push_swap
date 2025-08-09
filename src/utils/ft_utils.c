/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:33:12 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 17:34:16 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack_operation.h"

int	ft_check_is_sorted(t_stack *stack)
{
	t_dlist	*current;
	t_dlist	*next;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	next = stack->top->next;
	while (next)
	{
		if (current->value > next->value)
			return (0);
		current = next;
		next = next->next;
	}
	return (1);
}

int	ft_compare_top_max(t_stack *stack)
{
	t_dlist	*top;
	t_dlist	*next;

	if (!stack || stack->size < 2)
		return (0);
	top = stack->top;
	next = top->next;
	return (top->value > next->value);
}

int	ft_compare_top_min(t_stack *stack)
{
	t_dlist	*top;
	t_dlist	*next;

	if (!stack || stack->size < 2)
		return (0);
	top = stack->top;
	next = top->next;
	if (top->value < next->value)
		return (1);
	return (0);
}

int	ft_find_min(t_stack *stack)
{
	t_dlist	*current;
	int		min;
	int		min_pos;
	int		pos;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	ft_skip(t_stack *stack, int iter)
{
	int	size;

	size = stack->size;
	if (((size + 1) / 2) > iter)
	{
		while (iter--)
			ft_ra(stack);
	}
	else
	{
		iter = size - iter;
		while (iter--)
			ft_rra(stack);
	}
}
