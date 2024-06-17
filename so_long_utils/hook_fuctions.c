/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fuctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:56:24 by linda             #+#    #+#             */
/*   Updated: 2024/06/17 12:28:01 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

void	escape_close_window(mlx_key_data_t keydata,
									void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_close_window(game->mlx);
		// free_images(game_parameter);
	}
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
	if (game->map_data[idx_y][idx_x] == 'C' && keydata.action == MLX_RELEASE)
	{
		while (i < game->image_strawberry->count)
		{
			if (idx_x == (size_t)game->image_strawberry->instances[i].x / \
				game->pixels_per_tile && \
				idx_y == (size_t)game->image_strawberry->instances[i].y / \
				game->pixels_per_tile && \
				game->image_strawberry->instances[i].enabled)
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
	size_t	idx_x;
	size_t	idx_y;

	game = game_parameter;
	idx_x = game->image_princess->instances[0].x / game->pixels_per_tile;
	idx_y = game->image_princess->instances[0].y / game->pixels_per_tile;
	if (game->collected_berries_counter == (int)game->image_strawberry->count)
	{
		mlx_delete_image(game->mlx, game->image_castle_grey);
		set_images_on_gamefield(game, game->image_castle_color, 'E');
	}
	if (game->map_data[idx_y][idx_x] == 'E' && \
	game->collected_berries_counter >= (int)game->image_strawberry->count)
	{
		game->image_princess->instances[0].enabled = false;
		game->can_move = 0;
	}
}

void	hook_functions(mlx_key_data_t keydata, void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	escape_close_window(keydata, game_parameter);
	if (game->can_move == 1)
	{
		move_up_down_princess_hooks(keydata, game_parameter);
		print_moves_counter(game_parameter);
		move_left_right_princess_hooks(keydata, game_parameter);
		print_moves_counter(game_parameter);
		collect_berries(keydata, game_parameter);
		exit_castle(game_parameter);
	}
}
