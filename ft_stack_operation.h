/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operation.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:27:56 by nluchini          #+#    #+#             */
/*   Updated: 2025/07/31 11:15:59 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_OPERATION_H
# define FT_STACK_OPERATION_H

# include "ft_stack.h"

void	ft_sb(t_stack *stack);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_rb(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_ra(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

#endif