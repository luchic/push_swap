/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:10:33 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/29 22:37:08 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_chars(char **data, size_t len)
{
	size_t	i;

	if (!data)
		return ;
	i = 0;
	while (i < len && data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

// TODO: add checking
int	ft_check_data(char **data, int len)
{
	char	ch;
	int		i;
	int		j;

	if (!data || len <= 0)
		return (0);
	for (i = 0; i < len; i++)
	{
		if (!data[i])
			return (0);
		j = 0;
		while (data[i][j])
		{
			ch = data[i][j];
			j++;
		}
	}
	return (1);
}

// Function return size of total numbers i have.
int	ft_size_data(char **data, int len)
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
			if (*ch == ' ' && ft_isdigit(*(ch + 1)) || *ch == '-')
				size++;
			ch++;
		}
		i++;
	}
	return (size);
}

// TODO: this is return normal data of strings
// TODO: It's better to return allread a array of ints
int	*ft_normalize_data(char **data, int len)
{
	int	*res;
	int	size;

	size = ft_size_data(data, len);
	res = ft_calloc(size, sizeof(int));
}
