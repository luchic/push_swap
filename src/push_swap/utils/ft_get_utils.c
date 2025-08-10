/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:48:19 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 13:50:54 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_sort.h"

int	ft_get_max(t_stack *stack)
{
	t_dlist	*current;
	int		max;

	if (!stack || stack->size == 0)
		return (-1);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	ft_get_min(t_stack *stack)
{
	t_dlist	*current;
	int		min;

	if (!stack || stack->size == 0)
		return (-1);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	ft_get_top(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return (-1);
	return (stack->top->value);
}

int	ft_get_bottom(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return (-1);
	return (stack->bottom->value);
}

t_dlist	*ft_get_top_node(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return (NULL);
	return (stack->top);
}
