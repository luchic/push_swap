/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dublicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:29:46 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 11:41:09 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_dublicate(int *array, int size)
{
	int	i;
	int	j;

	if (!array || size < 0)
		return (0);
	if (size == 0 || size == 1)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
