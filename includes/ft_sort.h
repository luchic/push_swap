/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:19 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 15:25:41 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "ft_def.h"

// ======================== ft_sort.c ===============================
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

// ======================== ft_sort_three.c =========================
void	ft_sort_less3(t_stack *stack_a);

// ========================= ft_sort_five.c ==========================
void	ft_sort_less5(t_stack *stack_a, t_stack *stack_b);

// ========================= ft_move.c =========================
int		ft_move_top_a(t_stack *stack_a, t_stack *stack_b, t_chunks chunks);
int		ft_move_top_b(t_stack *stack_a, t_stack *stack_b, t_chunks chunks);
int		ft_move_bottom_a(t_stack *stack_a, t_stack *stack_b, t_chunks chunks);
int		ft_move_bottom_b(t_stack *stack_a, t_stack *stack_b, t_chunks chunks);

// ========================== ft_return.c =========================
void	ft_move_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks,
			t_type type);

// ========================== ft_split.c =========================
void	ft_split_chnks(t_stack *stack_a, t_stack *stack_b, t_chunks *chunks,
			t_type type);
#endif