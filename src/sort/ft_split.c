/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:24:41 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 15:56:04 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack.h"
#include "ft_utils.h"

void	ft_split_chnks(t_stack *stack_a, t_stack *stack_b, t_chunks *chunks,
		t_type type)
{
	int operations;
	int count;
	t_pos pos;

	operations = ft_get_size_all_chunks(chunks);
	count = 0;
	if (type == MID || type == MAX)
		pos = ft_get_position_all_chunks(stack_a, stack_b, chunks);

	while (count < operations)
	{
		if (type == MAX && pos == TOP_A)
			ft_move_top_a(stack_a, stack_b, *chunks);
		else if (type == MAX && pos == BOTTOM_A)
			ft_move_bottom_a(stack_a, stack_b, *chunks);
		else if (type == MID && pos == TOP_B)
			ft_move_top_b(stack_a, stack_b, *chunks);
		else if (type == MID && pos == BOTTOM_A)
			ft_move_bottom_a(stack_a, stack_b, *chunks);
		else if (type == MIN)
			ft_move_bottom_b(stack_a, stack_b, *chunks);
		count++;
	}
}