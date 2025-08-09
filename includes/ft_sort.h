/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:19 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 16:13:21 by nluchini         ###   ########.fr       */
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
}			t_chunks;

void		ft_sort(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_les_eq3(t_stack *stack_a);
void		ft_sort_les_eq5(t_stack *stack_a, t_stack *stack_b);

int			ft_move_top_a(t_stack *stack_a, t_stack *stack_b, t_chunks chunks);
int			ft_move_top_b(t_stack *stack_a, t_stack *stack_b, t_chunks chunks);
int			ft_move_bottom_a(t_stack *stack_a, t_stack *stack_b,
				t_chunks chunks);
int			ft_move_bottom_b(t_stack *stack_a, t_stack *stack_b,
				t_chunks chunks);
void		ft_split_chnks(t_stack *stack_a, t_stack *stack_b, t_chunks *chunks,
				t_type type);

void		ft_move_mid_bottoma_back(t_stack *stack_a, t_stack *stack_b,
				int size);

void		ft_move_mid_topb_back(t_stack *stack_a, t_stack *stack_b, int size);

void		ft_move_max_back(t_stack *stack_a, t_stack *stack_b,
				t_chunks chunks);

void		ft_move_mid_back(t_stack *stack_a, t_stack *stack_b,
				t_chunks chunks);

void		ft_move_min_back_three(t_stack *stack_a, t_stack *stack_b);

void		ft_move_min_back(t_stack *stack_a, t_stack *stack_b,
				t_chunks chunks);

void		ft_move_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks,
				t_type type);
#endif