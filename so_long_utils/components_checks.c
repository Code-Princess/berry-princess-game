/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:08:33 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/30 21:51:29 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_wall_borders(char **matrix, char *filepath)
{
	size_t	x;
	size_t	y;
	size_t	matrix_len;
	size_t	row_count;

	matrix_len = ft_strlen(matrix[0]);
	row_count = get_row_count(filepath);
	x = 0;
	while (x < matrix_len)
	{
		if (matrix[0][x] != '1' || matrix[row_count - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < row_count)
	{
		if (matrix[y][0] != '1' || matrix[y][matrix_len - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_map_components(char *components, char *filepath, char **matrix)
{
	size_t	i;
	size_t	map_len;
	size_t	map_height;
	int		*comp_counts;

	i = 0;
	comp_counts = (int *)malloc((ft_strlen(components)) * sizeof(int));
	map_len = ft_strlen(matrix[0]);
	map_height = get_row_count(filepath);
	while (i < ft_strlen(components))
	{
		comp_counts[i] = count_comps(components[i], matrix, \
		map_len, map_height);
		i++;
	}
	if (comp_counts[0] < 1 || comp_counts[1] != 1 || comp_counts[1] != 1)
		return (0);
	else
		return (1);
}

int	count_comps(char c, char **matrix, size_t length, size_t width)
{
	size_t	count;
	size_t	x;
	size_t	y;

	count = 0;
	y = 0;
	while (y < width)
	{
		x = 0;
		while (x < length)
		{
			if (matrix[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
