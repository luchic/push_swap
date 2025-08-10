/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:06:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 19:01:21 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_operation.h"
#include "ft_def.h"
#include "libft.h"

int	exec_instr(const char *op, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(op, "sa"))
		ft_swap(a);
	else if (!ft_strcmp(op, "sb"))
		ft_swap(b);
	else if (!ft_strcmp(op, "ss"))
		return (ft_swap(a), ft_swap(b), 1);
	else if (!ft_strcmp(op, "pa"))
		ft_push(b, a);
	else if (!ft_strcmp(op, "pb"))
		ft_push(a, b);
	else if (!ft_strcmp(op, "ra"))
		ft_rotate(a);
	else if (!ft_strcmp(op, "rb"))
		ft_rotate(b);
	else if (!ft_strcmp(op, "rr"))
		return (ft_rotate(a), ft_rotate(b), 1);
	else if (!ft_strcmp(op, "rra"))
		ft_rrotate(a);
	else if (!ft_strcmp(op, "rrb"))
		ft_rrotate(b);
	else if (!ft_strcmp(op, "rrr"))
		return (ft_rrotate(a), ft_rrotate(b), 1);
	else
		return (0);
	return (1);
}
