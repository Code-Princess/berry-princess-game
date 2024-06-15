/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fuctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:56:24 by linda             #+#    #+#             */
/*   Updated: 2024/06/15 15:03:25 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	escape_close_window(void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == 1)
		mlx_close_window(game->mlx);
}

void	move_up_down_princess_hooks(mlx_key_data_t keydata,
									void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE))
	{
		if (pre_check_wall_up(game->image_princess->instances,
				game->pixels_per_tile, game->map_data) == 0)
		{
			game->image_princess->instances[0].y -= game->pixels_per_tile;
			game->moves_counter++;
			ft_printf("MOVES: %d\n", game->moves_counter);
		}
	}
	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE))
	{
		if (pre_check_wall_down(game->image_princess->instances,
				game->pixels_per_tile, game->map_data) == 0)
		{
			game->image_princess->instances[0].y += game->pixels_per_tile;
			game->moves_counter++;
			ft_printf("MOVES: %d\n", game->moves_counter);
		}
	}
}

void	move_left_right_princess_hooks(mlx_key_data_t keydata,
									void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE))
	{
		if (pre_check_wall_left(game->image_princess->instances,
				game->pixels_per_tile, game->map_data) == 0)
		{
			game->image_princess->instances[0].x -= game->pixels_per_tile;
			game->moves_counter++;
			ft_printf("MOVES: %d\n", game->moves_counter);
		}
	}
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE))
	{
		if (pre_check_wall_right(game->image_princess->instances,
				game->pixels_per_tile, game->map_data) == 0)
		{
			game->image_princess->instances[0].x += game->pixels_per_tile;
			game->moves_counter++;
			ft_printf("MOVES: %d\n", game->moves_counter);
		}
	}
}

void	hook_functions(mlx_key_data_t keydata, void *game_parameter)
{
	t_game	*game;

	game = game_parameter;
	escape_close_window(game_parameter);
	move_up_down_princess_hooks(keydata, game_parameter);
	move_left_right_princess_hooks(keydata, game_parameter);
}
