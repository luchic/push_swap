/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:29:24 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 12:03:42 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_data(char **data, int len)
{
	int		size;
	char	*ch;
	int		i;

	if (!data || len <= 0)
		return (0);
	size = 0;
	i = 0;
	while (i < len)
	{
		ch = data[i];
		if (ft_isdigit(*ch) || *ch == '-')
			size++;
		while (*ch)
		{
			if (*ch == ' ' && (ft_isdigit(*(ch + 1)) || *(ch + 1) == '-'))
				size++;
			ch++;
		}
		i++;
	}
	return (size);
}

static void	ft_fill_array(char **data, int *array, int ldata, int larray)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	while (++i < ldata)
	{
		str = data[i];
		while (*str)
		{
			while (*str == ' ' && j < larray)
				str++;
			if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
			{
				array[j++] = ft_atoi(str);
				if (*str == '-')
					str++;
				while (ft_isdigit(*str))
					str++;
			}
			else if (*str)
				str++;
		}
	}
}

int	ft_get_array(int **array, char **data, int len)
{
	int	size;

	if (!array)
		return (-1);
	size = ft_size_data(data, len);
	*array = ft_calloc(size, sizeof(int));
	if (!*array)
		return (-1);
	ft_fill_array(data, *array, len, size);
	return (size);
}
