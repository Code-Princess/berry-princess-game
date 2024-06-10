/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:20:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/10 18:25:57 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

int	gamefield_textures_init(t_game *game)
{
	game->textures = malloc(5 * sizeof(mlx_image_t));
	if (game->textures == NULL)
		return (0);
	game->textures[0] = mlx_load_png("./textures/floor.png");
	if (game->textures[0] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->textures[1] = mlx_load_png("./textures/tree.png");
	if (game->textures[1] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->textures[2] = mlx_load_png("./textures/castle_grey.png");
	if (game->textures[2] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->textures[3] = mlx_load_png("./textures/castle_color.png");
	if (game->textures[3] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->textures[4] = mlx_load_png("./textures/princess.png");
	if (game->textures[4] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->textures[5] = mlx_load_png("./textures/strawberry.png");
	if (game->textures[5] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	return (1);
}

int	gamefield_textures_to_images_init(t_game *game)
{
	game->image_floor = mlx_texture_to_image(game->mlx, game->textures[0]);
	if (game->image_floor == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->image_tree = mlx_texture_to_image(game->mlx, game->textures[1]);
	if (game->image_tree == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->image_castle_grey = mlx_texture_to_image(game->mlx, game->textures[2]);
	if (game->image_castle_grey == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->image_castle_color = mlx_texture_to_image(game->mlx, game->textures[3]);
	if (game->image_castle_color == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->image_princess = mlx_texture_to_image(game->mlx, game->textures[4]);
	if (game->image_princess == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->image_strawberry = mlx_texture_to_image(game->mlx, game->textures[5]);
	if (game->image_strawberry == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	return (1);
}
int set_images_on_gamefield(t_game *game, mlx_image_t *img, char c)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < game->matrix_size->y)
	{
		x = 0;
		while (x < game->matrix_size->x)
		{
			if (game->map_data[y][x] == c)
				mlx_image_to_window(game->mlx, img, x * game->pixels_per_tile, y * game->pixels_per_tile);
			x++;
		}
		y++;
	}
	return (1);
}

void *gamefield_init(t_game *game)
{
	if (gamefield_textures_init(game) == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (gamefield_textures_to_images_init(game) == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (set_images_on_gamefield(game, game->image_floor, '0') == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (set_images_on_gamefield(game, game->image_tree, '1') == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (set_images_on_gamefield(game, game->image_strawberry, 'C') == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (set_images_on_gamefield(game, game->image_castle_grey, 'E') == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (set_images_on_gamefield(game, game->image_princess, 'P') == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (mlx_put_string(game->mlx, "move counts: ", game->pixels_per_tile / 2, game->matrix_size->y * game->pixels_per_tile) == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	return (game);
}
