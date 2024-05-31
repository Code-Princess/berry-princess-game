/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:01:22 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/31 23:00:48 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_valid_flood_fill_path(char **matrix, t_point *matrix_size,
		t_point *begin_position)
{
	flood_fill(matrix, matrix_size, *begin_position);
}

void	fill(char **tab, t_point size, t_point current_point, char to_fill)
{
	if (current_point.y < 0 || current_point.y >= size.y || current_point.x < 0
		|| current_point.x >= size.x
		|| tab[current_point.y][current_point.x] != to_fill)
		return ;
	tab[current_point.y][current_point.x] = 'F';
	fill(tab, size, (t_point){current_point.x - 1, current_point.y}, to_fill);
	fill(tab, size, (t_point){current_point.x + 1, current_point.y}, to_fill);
	fill(tab, size, (t_point){current_point.x, current_point.y - 1}, to_fill);
	fill(tab, size, (t_point){current_point.x, current_point.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

t_point	*get_start_position(char **matrix, size_t matrix_len,
		size_t matrix_height)
{
	size_t	x;
	size_t	y;
	t_point	*start_position;

	start_position = (t_point *)malloc(1 * sizeof(t_point));
	while (y < matrix_height)
	{
		while (x < matrix_len)
		{
			if (matrix[y][x] == 'P')
			{
				start_position->x = x;
				start_position->y = y;
				return (start_position);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}
