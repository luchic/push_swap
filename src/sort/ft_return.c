/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:28:34 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 17:32:58 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack.h"
#include "ft_stack_operation.h"
#include "ft_utils.h"

void	ft_move_mid_bottoma_back(t_stack *stack_a, t_stack *stack_b, int size)
{
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

void	ft_move_mid_topb_back(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2 && ft_compare_top_min(stack_b))
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

void	ft_move_max_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int	size;

	if (stack_a->size <= 3)
		return (ft_sort_les_eq3(stack_a));
	if (ft_get_position(stack_a, stack_b, &chunks, MAX) == BOTTOM_A)
	{
		size = ft_get_size_chunk(&chunks, MAX);
		if (size == 1)
			return (ft_rra(stack_a));
		return (ft_move_mid_bottoma_back(stack_a, stack_b, size));
	}
	size = ft_get_size_chunk(&chunks, MAX);
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

void	ft_move_mid_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int		size;
	t_pos	pos;

	pos = ft_get_position(stack_a, stack_b, &chunks, MID);
	size = ft_get_size_chunk(&chunks, MID);
	if (size == 1 && pos == TOP_B)
		return (ft_pa(stack_a, stack_b));
	else if (size == 1 && pos == BOTTOM_A)
		return (ft_rra(stack_a));
	if (pos == TOP_B)
		ft_move_mid_topb_back(stack_a, stack_b, size);
	else
		ft_move_mid_bottoma_back(stack_a, stack_b, size);
}

void	ft_move_min_back_three(t_stack *stack_a, t_stack *stack_b)
{
	ft_pa(stack_a, stack_b);
	if (ft_compare_top_min(stack_b))
		ft_sb(stack_b);
	if (ft_get_bottom(stack_b) > ft_get_top(stack_b))
	{
		ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		return (ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
	}
	else if (ft_get_bottom(stack_b) > ft_get_nel(stack_b, 1))
	{
		ft_pa(stack_a, stack_b);
		ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		return ;
	}
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_move_min_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int	size;

	// 	int size;
	size = ft_get_size_chunk(&chunks, MIN);
	if (size == 1)
		return (ft_pa(stack_a, stack_b));
	ft_move_mid_topb_back(stack_a, stack_b, size);
	// 	size = ft_get_size_chunk(&chunks, MIN);
	// 	if (size == 1)
	// 		return (ft_rrb(stack_b), ft_pa(stack_a, stack_b));
	// 	if (size == 2 )
	// 	{
	// 		if (ft_compare_top_min(stack_b))
	// 			return (ft_sb(stack_b), ft_pa(stack_a, stack_b), ft_pa(stack_a,
	//					stack_b));
	// 		return (ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
	// 	}
	// 	ft_move_min_back_three(stack_a, stack_b);
}

void	ft_move_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks,
		t_type type)
{
	if (type == MAX)
		ft_move_max_back(stack_a, stack_b, chunks);
	else if (type == MID)
		ft_move_mid_back(stack_a, stack_b, chunks);
	else if (type == MIN)
		ft_move_min_back(stack_a, stack_b, chunks);
}