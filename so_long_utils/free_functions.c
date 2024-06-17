/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:54:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/17 22:22:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_princess_game(t_game *game)
{
	free(game->game_window_size);
	free_matrix_entries(game->map_data, game->matrix_size_y);
	free(game->map_data);
	free(game->textures[0]);
	free(game->textures[1]);
	free(game->textures[2]);
	free(game->textures[3]);
	free(game->textures[4]);
	free(game->textures[5]);
	free(game->textures);
	mlx_delete_image(game->mlx, game->image_castle_color);
	mlx_delete_image(game->mlx, game->image_tree);
	mlx_delete_image(game->mlx, game->image_floor);
	mlx_delete_image(game->mlx, game->image_princess);
	mlx_delete_image(game->mlx, game->image_strawberry);
}

void	free_matrix_entries(char **matrix, size_t matrix_height)
{
	size_t	y;

	y = 0;
	while (y < matrix_height)
	{
		free(matrix[y]);
		y++;
	}
}
