/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:05:51 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/11 10:33:57 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	append_line(char **line, char *buff)
{
	static int	capacity;
	static int	size;
	char		*tmp;

	if (*line == NULL)
	{
		capacity = 8;
		size = 0;
		*line = ft_calloc(capacity, sizeof(char));
		if (*line == NULL)
			return (0);
	}
	if (size + 2 >= capacity)
	{
		capacity *= 2;
		tmp = ft_realloc(*line, size + 1, capacity * sizeof(char));
		if (tmp == NULL)
			return (0);
		*line = tmp;
	}
	(*line)[size] = buff[0];
	size++;
	return (1);
}

static void	free_line(char **line)
{
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
}

char	*ft_read_line_stdin(void)
{
	char	buff[1];
	char	*command;
	ssize_t	len;

	command = NULL;
	len = read(0, buff, 1);
	while (len > 0)
	{
		if (buff[0] == '\n' || buff[0] == '\0')
			return (command);
		if (!append_line(&command, buff))
			return (free_line(&command), NULL);
		len = read(0, buff, 1);
	}
	if (len == -1)
	{
		if (command != NULL)
			free_line(&command);
		return (NULL);
	}
	return (command);
}
