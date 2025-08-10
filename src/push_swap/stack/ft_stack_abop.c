/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_abop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:09:48 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/06 11:36:01 by nluchini         ###   ########.fr       */
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

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	ft_printf("ss\n");
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b )
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	ft_printf("rr\n");
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	ft_printf("rrr\n");
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}
