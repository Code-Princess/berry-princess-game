/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:20:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/07 13:22:49 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	gamefield_textures_init(t_game *game)
{
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_tree;
	mlx_texture_t	*texture_castle_color;
	mlx_texture_t	*texture_castle_grey;

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
	return (1);
}

int	component_textures_init(t_game *game)
{
	mlx_texture_t	*texture_strawberry;
	mlx_texture_t	*texture_princess;

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
	mlx_image_t		*image_floor;
	mlx_image_t		*image_tree;
	mlx_image_t		*image_castle_color;
	mlx_image_t		*image_castle_grey;

	image_floor = malloc(1 * sizeof(mlx_image_t));
	image_floor = mlx_texture_to_image(game->mlx, game->textures[0]);
	if (image_floor == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_tree = mlx_texture_to_image(game->mlx, game->textures[1]);
	if (image_tree == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_castle_grey = mlx_texture_to_image(game->mlx, game->textures[2]);
	if (image_castle_grey == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_castle_color = mlx_texture_to_image(game->mlx, game->textures[3]);
	if (image_castle_color == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	// if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
	// 	return (0);
	// mlx_loop(game->mlx);
	return (1);
}

int	component_textures_to_images_init(t_game *game)
{
	mlx_image_t		*image_strawberry;
	mlx_image_t		*image_princess;

	image_princess = mlx_texture_to_image(game->mlx, game->textures[4]);
	if (image_princess == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_strawberry = mlx_texture_to_image(game->mlx, game->textures[5]);
	if (image_strawberry == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	return (1);
}
