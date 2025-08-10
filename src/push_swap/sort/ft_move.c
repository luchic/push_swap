/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:51:59 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 16:58:18 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack_operation.h"
#include "ft_utils.h"

int	ft_move_top_a(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int	fir;

	fir = ft_get_top(stack_a);
	if (fir == -1)
		return (-1);
	if (fir >= chunks.max.min && fir <= chunks.max.max)
		ft_ra(stack_a);
	else if (fir >= chunks.mid.min && fir <= chunks.mid.max)
		ft_pb(stack_a, stack_b);
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
	{
		ft_pb(stack_a, stack_b);
		if (stack_b->size > 1)
			ft_rb(stack_b);
	}
	return (0);
}

int	ft_move_top_b(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int	fir;

	fir = ft_get_top(stack_b);
	if (fir == -1)
		return (-1);
	if (fir >= chunks.max.min && fir <= chunks.max.max)
		ft_pa(stack_a, stack_b);
	else if (fir >= chunks.mid.min && fir <= chunks.mid.max)
	{
		ft_pa(stack_a, stack_b);
		if (stack_a->size > 1)
			ft_ra(stack_a);
	}
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
		ft_rb(stack_b);
	return (0);
}

int	ft_move_bottom_a(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int	fir;

	fir = ft_get_bottom(stack_a);
	ft_rra(stack_a);
	if (fir >= chunks.mid.min && fir <= chunks.mid.max)
		ft_pb(stack_a, stack_b);
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
	{
		ft_pb(stack_a, stack_b);
		if (stack_b->size > 1)
			ft_rb(stack_b);
	}
	return (0);
}

int	ft_move_bottom_b(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int	fir;

	fir = ft_get_top(stack_b);
	if (fir >= chunks.max.min && fir <= chunks.max.max)
		ft_pa(stack_a, stack_b);
	if (fir >= chunks.mid.min && fir <= chunks.mid.max)
	{
		ft_pa(stack_a, stack_b);
		if (stack_a->size > 1)
			ft_ra(stack_a);
	}
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
		ft_rb(stack_b);
	return (0);
}
