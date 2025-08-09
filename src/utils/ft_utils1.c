/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:40:36 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 15:53:33 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

int	ft_is_max(t_stack *stack, int value)
{
	t_dlist	*current;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value > value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_is_sorted_top_dir(t_stack *stack, int n, int ascending)
{
	t_dlist	*current;
	t_dlist	*next;
	int		i;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	next = stack->top->next;
	i = 0;
	while (next && i < n - 1)
	{
		if (ascending && current->value > next->value)
			return (0);
		if (!ascending && current->value < next->value)
			return (0);
		current = next;
		next = next->next;
		i++;
	}
	return (1);
}
