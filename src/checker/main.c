/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:56:12 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/11 14:52:46 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_checker_parse.h"
#include "ft_error.h"
#include "ft_normalize.h"
#include "ft_parse.h"
#include "ft_sort.h"
#include "ft_stack.h"
#include "libft.h"
#include <stdlib.h>

void	print_error(void)
{
	ft_printf(ERROR_MESSAGE);
}

void	ft_start(int *array, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_init_stack(array, size);
	if (!stack_a)
		return (ft_error_message());
	stack_b = ft_init_stack(NULL, 0);
	if (!stack_b)
		return (ft_error_message(), ft_free_stack(stack_a));
	ft_run(stack_a, stack_b);
	if (ft_is_sorted(stack_a, stack_b))
		ft_printf(OK);
	else
		ft_printf(KO);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	int	*arra;
	int	*norm;
	int	size;

	if (argc < 2)
		return (0);
	if (!ft_validate_args(argv + 1, argc - 1))
		return (ft_error_message(), 0);
	arra = NULL;
	size = ft_get_array(&arra, argv + 1, argc - 1);
	if (!arra)
		return (ft_error_message(), 0);
	if (ft_check_dublicate(arra, size))
		return (ft_error_message(), free(arra), 0);
	norm = ft_normalize(arra, size);
	free(arra);
	if (!norm)
		return (ft_error_message(), 0);
	ft_start(norm, size);
	free(norm);
	return (0);
}
