/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:36:56 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 15:56:08 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack_operation.h"
#include "ft_utils.h"

void	ft_sort_les_eq3(t_stack *stack_a)
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
