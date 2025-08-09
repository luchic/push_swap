/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_aop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:52:46 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 16:56:51 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_operation.h"
#include "libft.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
		Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
		Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
		Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
		The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
		The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
		The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
		The last element becomes the first one.
rrr : rra and rrb at the same time. */

void	ft_sa(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	ft_printf("sa\n");
	ft_swap(stack);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	ft_printf("pa\n");
	ft_push(stack_b, stack_a);
}

void	ft_ra(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	ft_printf("ra\n");
	ft_rotate(stack);
}

void	ft_rra(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	ft_printf("rra\n");
	ft_rrotate(stack);
}
