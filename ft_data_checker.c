/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:10:33 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/31 21:25:01 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// static void	ft_free_chars(char **data, size_t len)
// {
// 	size_t	i;

// 	if (!data)
// 		return ;
// 	i = 0;
// 	while (i < len && data[i])
// 	{
// 		free(data[i]);
// 		i++;
// 	}
// 	free(data);
// }

// TODO: add checking
int	ft_check_data(char **data, int len)
{
	int	i;
	int	j;

	if (!data || len <= 0)
		return (0);
	i = -1;
	j = 0;
	while (++i < len)
	{
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] == '-')
				j++;
			if (!ft_isdigit(data[i][j]))
				return (0);
			while (ft_isdigit(data[i][j]))
				j++;
			if (data[i][j] != ' ' && data[i][j] != '\0')
				return (0);
			if (data[i][j] == ' ' && data[i][j + 1] != '\0')
				j++;
		}
	}
	return (1);
}

// Function return size of total numbers i have.
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

// TODO: this is return normal data of strings
// TODO: It's better to return allread a array of ints
int	ft_get_array(int **array, char **data, int len)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	if (!array)
		return (-1);
	size = ft_size_data(data, len);
	*array = ft_calloc(size, sizeof(int));
	if (!*array)
		return (-1);
	i = 0;
	j = 0;
	while (i < len)
	{
		str = data[i];
		while (*str)
		{
			while (*str == ' ' && j < size)
				str++;
			if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
			{
				(*array)[j++] = ft_atoi(str);
				if (*str == '-')
					str++;
				while (ft_isdigit(*str))
					str++;
			}
			else if (*str)
				str++;
		}
		i++;
	}
	return (size);
}
