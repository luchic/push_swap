/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:00:12 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/01 15:11:42 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

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

static void	ft_switch_nodes(t_dlist *first, t_dlist *second)
{
	if (!first || !second)
		return ;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
}

void	ft_swap(t_stack *stack)
{
	t_dlist	*first;
	t_dlist	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	ft_switch_nodes(first, second);
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	ft_push(t_stack *from, t_stack *to)
{
	t_dlist	*node;

	if (!from || !to || from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	if (from->top)
		from->top->prev = NULL;
	from->size--;
	node->next = to->top;
	if (to->top)
		to->top->prev = node;
	to->top = node;
	if (to->size == 0)
		to->bottom = node;
	to->size++;
}

void	ft_rotate(t_stack *stack)
{
	t_dlist	*first;
	t_dlist	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	stack->bottom = first;
}

void	ft_rrotate(t_stack *stack)
{
	t_dlist	*first;
	t_dlist	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->top = last;
}

// void ft_sa(t_stack *stack)
// {
// 	if (!stack || stack->size < 2)
// 		return ;

// }