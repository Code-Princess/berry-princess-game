/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:08:33 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/29 22:46:54 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_components(char *filepath, char **matrix, char component)
{
	size_t		x;
	size_t		y;
	size_t	matrix_len;
	size_t	matrix_height;

	x = 0;
	y = 0;
	matrix_len = ft_strlen(matrix[0]);
	matrix_height = get_row_count(filepath);

	while (x < matrix_len)
	{
		while (y < matrix_height)
		{
			if (matrix[][] == component)
			{
				/* code */
			}
			
			j++;
		}
		i++;
	}
	return (1);
}
