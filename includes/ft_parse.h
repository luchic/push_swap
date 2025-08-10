/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:57:01 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/10 15:01:34 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

/**
 * @brief  Function to parse input data into an integer array.
 * @note   If the get overflows, it returns -1.
 * @param  array: Pointer to an integer array.
 * @param  data: Input
 * @param  len: Size of the input data.
 * @retval Size of the parsed array, or -1 on error.
 */
int	ft_get_array(int **array, char **data, int len);

/**
 * @brief  Function to validate the input arguments.
 * @param  data: Input data as an array of strings.
 * @param  len: Length of the input data.
 * @retval 1 if valid, 0 if invalid.
 */
int	ft_validate_args(char **data, int len);

/**
 * @brief  Function to check for duplicate values in an integer array.
 * @param  array: Pointer to the integer array.
 * @param  size: Size of the array.
 * @retval 1 if duplicates are found, 0 otherwise.
 */
int	ft_check_dublicate(int *array, int size);

#endif