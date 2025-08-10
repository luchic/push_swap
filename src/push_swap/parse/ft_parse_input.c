/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:29:17 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 14:58:52 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_validate_args(char **data, int len)
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
