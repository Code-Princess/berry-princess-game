/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:22:39 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/17 16:13:47 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

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

void	print_moves_counter(void *game_parameter)
{
	t_game				*game;
	static mlx_image_t	*string;
	char				*str_move_counter;

	game = game_parameter;
	str_move_counter = ft_itoa(game->moves_counter);
	mlx_delete_image(game->mlx, string);
	string = mlx_put_string(game->mlx, str_move_counter, \
		game->pixels_per_tile + game->pixels_per_tile, \
		game->matrix_size_y * game->pixels_per_tile + 5);
	free(str_move_counter);
}
