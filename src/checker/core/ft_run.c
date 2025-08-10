/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:04:34 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 19:42:39 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_parse.h"
#include "ft_error.h"
#include <stdlib.h>

void	ft_run(t_stack *a, t_stack *b)
{
	char	*command;

	command = ft_read_line_stdin();
	while (command && *command)
	{
		if (!exec_instr(command, a, b))
		{
			ft_error_message();
			free(command);
			return ;
		}
		free(command);
		command = ft_read_line_stdin();
	}
}
