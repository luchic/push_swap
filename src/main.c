/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:12:25 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 14:59:06 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stack.h"
#include "ft_stack_operation.h"
#include "ft_utils.h"
#include "libft.h"
#include <stdlib.h>

// void	ft_print_data(t_stack *stack)
// {
// 	t_dlist	*current;

// 	if (!stack || stack->size == 0)
// 		return ;
// 	current = stack->top;
// 	while (current)
// 	{
// 		ft_printf("%d ", current->value);
// 		current = current->next;
// 	}
// 	ft_printf("\n");
// }

void	ft_error_message(void)
{
	ft_printf("Error\n");
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
	ft_sort(stack_a, stack_b);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	int	*arra;
	int	*norm;
	int	size;

	if (argc < 2)
		return (ft_error_message(), 0);
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
