/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operation.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:27:56 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/30 21:28:50 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_OPERATION_H
# define FT_STACK_OPERATION_H

# include "ft_stack.h"

void	ft_swap(t_stack *stack);
void	ft_push(t_stack *from, t_stack *to);
void	ft_rotate(t_stack *stack);
void	ft_rrotate(t_stack *stack);

#endif