/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:28:34 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 20:20:59 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack.h"
#include "ft_stack_operation.h"
#include "ft_utils.h"

static void	ft_return_topa(t_stack *stack_a, t_stack *stack_b, t_type type,
		t_chunks chunks)
{
	int	size;

	if (stack_a->size <= 3)
		return (ft_sort_les_eq3(stack_a));
	size = ft_get_size_chunk(&chunks, type);
	if (size == 2 && ft_compare_top_max(stack_a))
		return (ft_sa(stack_a));
	if (ft_is_sorted_top_dir(stack_a, size, 1))
		return ;
	if (ft_compare_top_max(stack_a))
	{
		ft_sa(stack_a);
		if (ft_is_sorted_top_dir(stack_a, size, 1))
			return ;
	}
	if (ft_get_top(stack_a) < ft_get_nel(stack_a, 2))
		return (ft_ra(stack_a), ft_sa(stack_a), ft_rra(stack_a));
	else if (ft_get_top(stack_a) > ft_get_nel(stack_a, 2) && ft_get_nel(stack_a,
			1) > ft_get_nel(stack_a, 2))
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
}

static void	ft_return_topb(t_stack *stack_a, t_stack *stack_b, t_type type,
		t_chunks chunks)
{
	int	size;

	size = ft_get_size_chunk(&chunks, type);
	if (size == 1)
		return (ft_pa(stack_a, stack_b));
	else if (size == 2 && ft_compare_top_min(stack_b))
		return (ft_sb(stack_b), ft_pa(stack_a, stack_b), ft_pa(stack_a,
				stack_b));
	else if (size == 2)
		return (ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
	if (ft_get_top(stack_b) < ft_get_top(stack_a))
		return (ft_pa(stack_a, stack_b));
	else if (ft_get_top(stack_b) < ft_get_nel(stack_a, 1))
		return (ft_pa(stack_a, stack_b), ft_sa(stack_a));
	ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	ft_sa(stack_a);
	ft_rra(stack_a);
}

static void	ft_return_bottoma(t_stack *stack_a, t_stack *stack_b, t_type type,
		t_chunks chunks)
{
	int	size;

	size = ft_get_size_chunk(&chunks, type);
	if (size == 1)
		return (ft_rra(stack_a));
	if (size == 2)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		if (ft_compare_top_max(stack_a))
			return (ft_sa(stack_a));
		return ;
	}
	ft_rra(stack_a);
	ft_rra(stack_a);
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
	if (ft_get_bottom(stack_a) < ft_get_top(stack_a))
		return (ft_rra(stack_a));
	else if (ft_get_bottom(stack_a) < ft_get_nel(stack_a, 1))
		return (ft_rra(stack_a), ft_sa(stack_a));
	ft_pb(stack_a, stack_b);
	ft_rra(stack_a);
	ft_sa(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_move_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks,
		t_type type)
{
	t_pos	pos;

	pos = ft_get_position(stack_a, stack_b, &chunks, type);
	if (pos == TOP_A)
		ft_return_topa(stack_a, stack_b, type, chunks);
	else if (pos == TOP_B)
		ft_return_topb(stack_a, stack_b, type, chunks);
	else if (pos == BOTTOM_A)
		ft_return_bottoma(stack_a, stack_b, type, chunks);
	else
		ft_return_topb(stack_a, stack_b, type, chunks);
}
