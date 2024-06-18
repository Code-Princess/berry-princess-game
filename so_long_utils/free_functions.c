/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:54:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/18 12:22:52 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_princess_game(t_game *game)
{
	free_matrix_entries(game->map_data, game->matrix_size_y);
	free(game->map_data);
	mlx_delete_texture(game->textures[0]);
	mlx_delete_texture(game->textures[1]);
	mlx_delete_texture(game->textures[2]);
	mlx_delete_texture(game->textures[3]);
	mlx_delete_texture(game->textures[4]);
	mlx_delete_texture(game->textures[5]);
	free(game->textures);
	mlx_delete_image(game->mlx, game->image_castle_color);
	mlx_delete_image(game->mlx, game->image_princess);
	mlx_delete_image(game->mlx, game->image_tree);
	mlx_delete_image(game->mlx, game->image_strawberry);
	mlx_delete_image(game->mlx, game->image_floor);
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
