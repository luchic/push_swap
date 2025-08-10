/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:37:06 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 10:57:11 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>

void	ft_free_dlist(t_dlist *head)
{
	t_dlist	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->top)
		ft_free_dlist(stack->top);
	free(stack);
	stack = NULL;
}
