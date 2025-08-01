/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:32:06 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/01 15:46:29 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

int	ft_check_data(char **data, int len);
int	ft_get_array(int **array, char **data, int len);
int	ft_check_dublicate(int *array, int size);
int	*ft_normalize(int *array, int size);

#endif