/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:51 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/06 15:02:59 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Lib_ft/libft.h"	

t_game	*game_init(t_game *game)
{
	size_t	pixels_per_tile;

	pixels_per_tile = 50;
	game->game_window_size = malloc(1 * sizeof(t_point));
	game->game_window_size->x = game->matrix_size->x * pixels_per_tile;
	game->game_window_size->y = game->matrix_size->y * pixels_per_tile;
	game->moves_counter = 0;
	return (game);
}

int	set_game_field(t_game *game, char *texture_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(texture_path);
	if (texture == NULL)
	{
		ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1);
		return (0);
	}
	img = mlx_texture_to_image(game->mlx, texture);
	if (img == NULL)
	{
		ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1);
		return (0);
	}
	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
		return (0);
	// mlx_loop(game->mlx);
	return (1);
}
