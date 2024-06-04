/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:08:33 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/04 14:13:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>

int	check_wall_borders(char **matrix, size_t matrix_len, size_t matrix_height)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < matrix_len)
	{
		if (matrix[0][x] != '1' || matrix[matrix_height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < matrix_height)
	{
		if (matrix[y][0] != '1' || matrix[y][matrix_len - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_valid_component_counts(char *components, char **matrix, \
size_t map_len, size_t map_height)
{
	size_t	i;
	int		*comp_counts;

	i = 0;
	comp_counts = (int *)malloc((ft_strlen(components)) * sizeof(int));
	if (comp_counts == NULL)
		return (0);
	while (i < ft_strlen(components))
	{
		comp_counts[i] = count_components(components[i], \
		matrix, map_len, map_height);
		i++;
	}
	if (comp_counts[0] < 1 || comp_counts[1] != 1 || comp_counts[1] != 1)
		return (free(comp_counts), comp_counts = NULL, 0);
	else
		return (free(comp_counts), comp_counts = NULL, 1);
}

int	count_components(char c, char **matrix, size_t length, size_t width)
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

int	check_valid_map_elements(char *components, char **matrix, \
size_t matrix_len, size_t matrix_height)
{
	size_t	x;
	size_t	y;
	size_t	i;

	y = 0;
	while (y < matrix_height)
	{
		x = 0;
		while (x < matrix_len)
		{
			i = 0;
			while (i < ft_strlen(components))
			{
				if (matrix[y][x] == components[i])
					break ;
				else
					i++;
			}
			if (i == ft_strlen(components))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
