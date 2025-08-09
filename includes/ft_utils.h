/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:32:06 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 15:53:46 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

// ============= ft_data_checker.c ================
int			ft_check_data(char **data, int len);
int			ft_get_array(int **array, char **data, int len);
int			ft_check_dublicate(int *array, int size);

// ============= ft_normalization.c ================
int			*ft_normalize(int *array, int size);

// ============= ft_utils.c ================
int			ft_check_is_sorted(t_stack *stack);
int			ft_compare_top_max(t_stack *stack);
int			ft_compare_top_min(t_stack *stack);
int			ft_find_min(t_stack *stack);
void		ft_skip(t_stack *stack, int iter);
int			ft_is_max(t_stack *stack, int value);

int			ft_get_max(t_stack *stack);

int			ft_get_min(t_stack *stack);

int			ft_get_top(t_stack *stack);

int			ft_get_bottom(t_stack *stack);

t_dlist		*ft_get_top_node(t_stack *stack);

t_dlist		*ft_get_nnode(t_stack *stack, int n);

int			ft_get_nel(t_stack *stack, int n);

int			ft_get_size_chunk(const t_chunks *chunks, t_type type);

int			ft_get_size_all_chunks(const t_chunks *chunks);

t_chunks	ft_set_chunks_updated(t_chunks chunks, t_type type);

t_pos		ft_get_position_all_chunks(t_stack *stack_a, t_stack *stack_b,
				t_chunks *chunks);

t_pos		ft_get_max_position(t_stack *stack_a, t_chunks *chunks);
t_pos		ft_get_mid_position(t_stack *stack_b, t_chunks *chunks);
t_pos		ft_get_position(t_stack *stack_a, t_stack *stack_b,
				t_chunks *chunks, t_type type);

int			ft_is_sorted_top_dir(t_stack *stack, int n, int ascending);

#endif