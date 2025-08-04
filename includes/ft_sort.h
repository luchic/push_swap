/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:19 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/04 17:59:34 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "ft_stack.h"

typedef struct s_chunks
{
	int	min_min;
	int	min_max;
	int	mid_min;
	int	mid_max;
	int	max_min;
	int	max_max;
	int	size;
}		t_chunks;

typedef enum e_pos
{
	TOP_A,
	TOP_B,
	BOTTOM_B,
} t_pos;

void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif