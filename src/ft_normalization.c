/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:28:12 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/01 15:56:26 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_get_weight(int num, int *array, int size)
{
	int weight;
	int i;

	weight = 0;
	i = -1;
	while (++i < size)
	{
		if (array[i] < num)
			weight++;
	}
	return (weight);
}

int *ft_normalize(int *array, int size)
{
	int *normalized_array;
	int i;
	
	if (!array || size <= 0)
		return (NULL);
	
	normalized_array = ft_calloc(size, sizeof(int));
	if (!normalized_array)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		normalized_array[i] = ft_get_weight(array[i], array, size);
	}
	return (normalized_array);
}
