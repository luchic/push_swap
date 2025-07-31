/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:12:25 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/31 21:25:16 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_stack.h"
#include "ft_stack_operation.h"
#include "ft_sort.h"
#include "ft_utils.h"

void ft_print_data(t_stack *stack)
{
	t_dlist *current;

	if (!stack || stack->size == 0)
		return;
	current = stack->top;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

int main(int argc, char **argv)
{
	// Example usage of ft_printf
	if (argc < 2)
	{
		ft_printf("Error\n");
	}
	int *arra = NULL; 
	int size = ft_get_array(&arra, argv + 1, argc - 1);
	if (!arra)
	{
		ft_printf("Error\n");
		return (1);
	}

	t_stack *stack_a = ft_init_stack(arra, size);
	t_stack *stack_b = ft_init_stack(NULL, 0);

	ft_printf("Before sorting:\n");
	ft_print_data(stack_a);
	ft_sort(stack_a, stack_b);
	ft_printf("After sorting:\n");
	ft_print_data(stack_a);

	return 0;
}