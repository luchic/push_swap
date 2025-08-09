/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:39:29 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 15:56:14 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack_operation.h"
#include "ft_utils.h"

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

void	ft_sort_les_eq5(t_stack *stack_a, t_stack *stack_b)
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
