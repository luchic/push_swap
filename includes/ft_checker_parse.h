/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_parse.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:00 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 19:50:47 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_PARSE_H
# define FT_CHECKER_PARSE_H
# include "ft_def.h"

char	*ft_read_line_stdin(void);
int		exec_instr(const char *op, t_stack *a, t_stack *b);

#endif