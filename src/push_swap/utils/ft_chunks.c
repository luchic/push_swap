/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:21:38 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 20:15:17 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

static int	set_value(int *div, int *shift, t_chunks *chunks, t_type type)
{
	int	size;

	if (type == MIN)
	{
		size = chunks->min.max - chunks->min.min + 1;
		*div = size / 3;
		*shift = chunks->min.min;
	}
	else if (type == MID)
	{
		size = chunks->mid.max - chunks->mid.min + 1;
		*div = size / 3;
		*shift = chunks->mid.min;
	}
	else
	{
		size = chunks->max.max - chunks->max.min + 1;
		*div = size / 3;
		*shift = chunks->max.min;
	}
	return (size);
}

t_chunks	ft_set_chunks_updated(t_chunks chunks, t_type type)
{
	int			div;
	int			shift;
	int			size;
	t_chunks	tmp;

	size = set_value(&div, &shift, &chunks, type);
	if (type == MIN)
		tmp.max.max = chunks.min.max;
	else if (type == MID)
		tmp.max.max = chunks.mid.max;
	else
		tmp.max.max = chunks.max.max;
	tmp.min.min = shift;
	tmp.min.max = shift + div - 1;
	tmp.mid.min = shift + div;
	if (size % 3 == 2)
		tmp.mid.max = shift + 2 * div;
	else
		tmp.mid.max = shift + 2 * div - 1;
	if (size % 3 == 2)
		tmp.max.min = shift + 2 * div + 1;
	else
		tmp.max.min = shift + 2 * div;
	return (tmp);
}
