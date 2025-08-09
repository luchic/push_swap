/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 16:13:27 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack_operation.h"
#include "ft_utils.h"
#include "libft.h"

void	ft_skip_stack(t_stack *stack, int n, void (*ft_r)(t_stack *))
{
	if (n < 0)
		return ;
	while (n--)
		ft_r(stack);
}

void	sort_core(t_stack *stack_a, t_stack *stack_b, t_chunks chunks,
		t_type type)
{
	int			div;
	int			shift;
	int			size;
	t_chunks	tmp;

	if (type == MIN && stack_b->size != ft_get_size_chunk(&chunks, MIN))
		ft_skip_stack(stack_b, ft_get_size_chunk(&chunks, MIN), ft_rrb);
	if (ft_get_size_chunk(&chunks, type) <= 3)
		return (ft_move_back(stack_a, stack_b, chunks, type));
	tmp = ft_set_chunks_updated(chunks, type);
	ft_split_chnks(stack_a, stack_b, &tmp, type);
	if (type == MID && chunks.mid.pos == TOP_B || type == MIN)
		tmp.mid.pos = BOTTOM_A;
	sort_core(stack_a, stack_b, tmp, MAX);
	sort_core(stack_a, stack_b, tmp, MID);
	sort_core(stack_a, stack_b, tmp, MIN);
}

void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_chunks	chunks;

	chunks.max.min = 0;
	chunks.max.max = stack_a->size - 1;
	chunks.max.pos = TOP_A;
	sort_core(stack_a, stack_b, chunks, MAX);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_check_is_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
		return (ft_sort_les_eq3(stack_a));
	else if (stack_a->size <= 5)
		return (ft_sort_les_eq5(stack_a, stack_b));
	ft_chunk_sort(stack_a, stack_b);
}
