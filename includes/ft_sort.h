/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:19 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/06 20:55:10 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "ft_stack.h"

typedef enum e_pos
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B,
}			t_pos;

typedef enum e_type
{
	MIN,
	MID,
	MAX,
}			t_type;

typedef struct s_chunk
{
	t_pos	pos;
	int		min;
	int		max;
}			t_chunk;

typedef struct s_chunks
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
	int		min_min;
	int		min_max;
	int		mid_min;
	int		mid_max;
	int		max_min;
	int		max_max;
	int		size;
}			t_chunks;

void		ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif