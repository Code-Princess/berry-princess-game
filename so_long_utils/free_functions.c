/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:54:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/16 21:51:18 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_textures(t_game *game) //not used
{
	mlx_delete_texture(game->textures[0]);
	mlx_delete_texture(game->textures[1]);
	mlx_delete_texture(game->textures[2]);
	mlx_delete_texture(game->textures[3]);
	mlx_delete_texture(game->textures[4]);
	mlx_delete_texture(game->textures[5]);
	free(game->textures);
}

void	free_images(void *game_parameter) // not used
{
	t_game	*game;

	game = game_parameter;
	mlx_delete_image(game->mlx, game->image_castle_color);
	mlx_delete_image(game->mlx, game->image_tree);
	mlx_delete_image(game->mlx, game->image_strawberry);
	mlx_delete_image(game->mlx, game->image_floor);
	// mlx_delete_image(game->mlx, game->image_princess);
}

void	free_matrix(char **matrix, t_point *matrix_size)
{
	size_t	y;

	y = 0;
	while (y < matrix_size->y)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}
