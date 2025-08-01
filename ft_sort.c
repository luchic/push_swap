/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/01 14:31:24 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack_operation.h"

static int	ft_check_is_sorted(t_stack *stack)
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

static int	ft_compare_top_max(t_stack *stack)
{
	t_dlist	*top;
	t_dlist	*next;

	if (!stack || stack->size < 2)
		return (0);
	top = stack->top;
	next = top->next;
	if (top->value > next->value)
		return (1);
	return (0);
}

static int	ft_compare_top_min(t_stack *stack)
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

static void	ft_skip(t_stack *stack, int iter)
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

static void	_brootforce_ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	ind;

	while (stack_a->top->next)
	{
		ind = ft_find_min(stack_a);
		ft_skip(stack_a, ind);
		ft_pb(stack_a, stack_b);
	}
	while (stack_b->top)
	{
		ft_pa(stack_a, stack_b);
	}
}

static void	ft_sort_les_eq3(t_stack *stack_a)
{
	if (stack_a->size == 1)
		return ;
	if (stack_a->size == 2)
	{
		if (ft_compare_top_max(stack_a))
			ft_sa(stack_a);
		return ;
	}
	if (stack_a->top->value > stack_a->bottom->value
		&& stack_a->top->value > stack_a->top->next->value)
		ft_ra(stack_a);
	else if (stack_a->top->value > stack_a->bottom->value
		&& stack_a->top->value < stack_a->top->next->value)
		ft_rra(stack_a);
	if (ft_check_is_sorted(stack_a))
		return ;
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
	if (ft_check_is_sorted(stack_a))
		return ;
	ft_rra(stack_a);
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
}

static int	ft_is_max(t_stack *stack, int value)
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

static void	ft_merg_sorted_tail_4(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_max(stack_a, stack_b->top->value))
		return (ft_pa(stack_a, stack_b), ft_ra(stack_a));
	if (stack_a->top->value >= stack_b->top->value)
		return (ft_pa(stack_a, stack_b));
	if (stack_a->top->next->value >= stack_b->top->value)
		return (ft_ra(stack_a), ft_pa(stack_a, stack_b), ft_rra(stack_a));
	else
	{
		ft_rra(stack_a);
		return (ft_pa(stack_a, stack_b), ft_ra(stack_a), ft_ra(stack_a));
	}
}

static void	ft_sort_les_eq5(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	index = ft_find_min(stack_a);
	ft_skip(stack_a, index);
	if (ft_check_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	if (stack_a->size == 4)
	{
		index = ft_find_min(stack_a);
		ft_skip(stack_a, index);
		ft_pb(stack_a, stack_b);
	}
	ft_sort_les_eq3(stack_a);
	ft_pa(stack_a, stack_b);
	if (stack_b->size == 1)
		ft_pa(stack_a, stack_b);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_check_is_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
		return (ft_sort_les_eq3(stack_a));
	else if (stack_a->size <= 5)
		return (ft_sort_les_eq5(stack_a, stack_b));
}
