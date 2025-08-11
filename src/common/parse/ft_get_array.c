/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:29:24 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/11 14:39:41 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

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

static int	ft_fill_int(char *str, int *array, int index, int size)
{
	char	*tmp;
	int		j;

	j = index;
	while (*str)
	{
		while (*str == ' ' && index < size)
			str++;
		if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
		{
			array[index++] = ft_atoi(str);
			tmp = ft_itoa(array[index - 1]);
			if (ft_strncmp(tmp, str, ft_strlen(tmp)) != 0
				&& str[ft_strlen(tmp)] != ' ' && str[ft_strlen(tmp)] != '\0')
				return (free(tmp), -1);
			free(tmp);
			if (*str == '-')
				str++;
			while (ft_isdigit(*str))
				str++;
		}
		else if (*str)
			str++;
	}
	return (index - j);
}

static void	ft_fill_array(char **data, int **array, int ldata, int larray)
{
	int		i;
	int		j;
	int		index;
	char	*str;

	i = -1;
	j = 0;
	while (++i < ldata)
	{
		str = data[i];
		index = ft_fill_int(str, *array, j, larray);
		if (index == -1)
		{
			free(*array);
			*array = NULL;
			return ;
		}
		j += index;
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
	ft_fill_array(data, array, len, size);
	if (!*array)
		return (-1);
	return (size);
}
