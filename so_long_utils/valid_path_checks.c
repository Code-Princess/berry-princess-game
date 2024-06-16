/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:01:22 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/16 20:13:03 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

int	check_valid_flood_fill_path(char **matrix, t_point *matrix_size,
		t_point *begin_position, char *components_to_reach)
{
	t_point	index;
	size_t	i;

	flood_fill(matrix, matrix_size, begin_position);
	index.y = 0;
	while (index.y < matrix_size->y)
	{
		index.x = 0;
		while (index.x < matrix_size->x)
		{
			i = 0;
			while (i < ft_strlen(components_to_reach))
			{
				if (matrix[index.y][index.x] == components_to_reach[i])
					return (ft_printf("Error\nInvalid map input! " \
									"Not reachable components!\n"), 0);
				i++;
				if (i == ft_strlen(components_to_reach))
					break ;
			}
			index.x++;
		}
		index.y++;
	}
	return (free(begin_position), 1);
}

void	fill(char **tab, t_point *size, t_point *current_point, char *to_fill)
{
	if (current_point->y >= size->y || \
		current_point->x >= size->x || \
		current_point->x >= size->x || \
		!char_in_set(tab[current_point->y][current_point->x], to_fill))
		return ;
	tab[current_point->y][current_point->x] = 'F';
	current_point->x -= 1;
	fill(tab, size, current_point, to_fill);
	current_point->x += 2;
	fill(tab, size, current_point, to_fill);
	current_point->x -= 1;
	current_point->y -= 1;
	fill(tab, size, current_point, to_fill);
	current_point->y += 2;
	fill(tab, size, current_point, to_fill);
	current_point->y -= 1;
}

void	flood_fill(char **tab, t_point *size, t_point *begin)
{
	char	*components_to_flood;

	components_to_flood = "CEP0";
	fill(tab, size, begin, components_to_flood);
}

t_point	*get_start_position(char **matrix, size_t matrix_len,
		size_t matrix_height)
{
	size_t	x;
	size_t	y;
	t_point	*start_position;

	start_position = (t_point *)malloc(1 * sizeof(t_point));
	y = 0;
	while (y < matrix_height)
	{
		x = 0;
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
