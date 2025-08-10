/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:39:53 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 15:48:47 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>

# include "ft_def.h"

t_stack	*ft_init_stack(int *array, size_t len);
void	ft_free_dlist(t_dlist *head);
void	ft_free_stack(t_stack *stack);

#endif