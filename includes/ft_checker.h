/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:33:55 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 19:49:07 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "ft_def.h"

# define OK "OK\n"
# define KO "KO\n"

void	ft_run(t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *a, t_stack *b);

#endif