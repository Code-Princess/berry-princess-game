/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:01:22 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/18 16:27:04 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

int	check_valid_flood_fill_path(char **matrix,
		t_game *game, char *components_to_reach)
{
	t_point	index;
	size_t	i;

	flood_fill(matrix, game);
	index.y = 0;
	while (index.y < game->matrix_size_y)
	{
		index.x = 0;
		while (index.x < game->matrix_size_x)
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
	return (1);
}

void	fill(char **tab, t_game *game, char *to_fill)
{
	if (game->start_pos_y >= game->matrix_size_y || \
		game->start_pos_x >= game->matrix_size_x || \
		!char_in_set(tab[game->start_pos_y][game->start_pos_x], to_fill))
		return ;
	tab[game->start_pos_y][game->start_pos_x] = 'F';
	game->start_pos_x -= 1;
	fill(tab, game, to_fill);
	game->start_pos_x += 2;
	fill(tab, game, to_fill);
	game->start_pos_x -= 1;
	game->start_pos_y -= 1;
	fill(tab, game, to_fill);
	game->start_pos_y += 2;
	fill(tab, game, to_fill);
	game->start_pos_y -= 1;
}

void	flood_fill(char **tab, t_game *game)
{
	char	*components_to_flood;

	components_to_flood = "CEP0";
	fill(tab, game, components_to_flood);
}

void	get_start_position(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->matrix_size_y)
	{
		x = 0;
		while (x < game->matrix_size_x)
		{
			if (game->map_data[y][x] == 'P')
			{
				game->start_pos_x = x;
				game->start_pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
