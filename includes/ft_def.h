/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:16:59 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 15:17:50 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEF_H
# define FT_DEF_H

typedef struct s_dlist
{
	int				value;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_stack
{
	t_dlist			*top;
	t_dlist			*bottom;
	int				size;
}					t_stack;

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
	int		min;
	int		max;
}			t_chunk;

typedef struct s_chunks
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}			t_chunks;

#endif