/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fuctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:56:24 by linda             #+#    #+#             */
/*   Updated: 2024/06/15 18:34:00 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	escape_close_window(void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == 1)
		mlx_close_window(game->mlx);
}

void	collect_berries(mlx_key_data_t keydata, void *game_parameter)
{
	t_game	*game;
	size_t	idx_x;
	size_t	idx_y;
	size_t	i;

	i = 0;
	game = game_parameter;
	idx_x = game->image_princess->instances[0].x / game->pixels_per_tile;
	idx_y = game->image_princess->instances[0].y / game->pixels_per_tile;
	if (game->map_data[idx_y][idx_x] == 'C')
	{
		while (i < game->image_strawberry->count)
		{
			if (idx_x == (size_t)game->image_strawberry->instances[i].x / \
				game->pixels_per_tile && \
				idx_y == (size_t)game->image_strawberry->instances[i].y / \
				game->pixels_per_tile && keydata.action == MLX_RELEASE)
			{
				game->image_strawberry->instances[i].enabled = false;
				game->collected_berries_counter++;
			}
			i++;
		}
	}
}

void	exit_castle(void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	if (game->collected_berries_counter == (int)game->image_strawberry->count)
	{
		mlx_delete_image(game->mlx, game->image_castle_grey);
		set_images_on_gamefield(game, game->image_castle_color, 'E');
	}
}

void	hook_functions(mlx_key_data_t keydata, void *game_parameter)
{
	escape_close_window(game_parameter);
	move_up_down_princess_hooks(keydata, game_parameter);
	print_moves_counter(game_parameter);
	move_left_right_princess_hooks(keydata, game_parameter);
	print_moves_counter(game_parameter);
	collect_berries(keydata, game_parameter);
	exit_castle(game_parameter);
}
