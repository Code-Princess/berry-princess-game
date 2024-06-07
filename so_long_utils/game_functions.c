/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:51 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/07 13:05:50 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

t_game	*game_init(t_game *game)
{
	if (game_window_init(t_game *game) == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (gamefield_textures_init(game) == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (component_textures_init(game) == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	mlx_loop(game->mlx);
	return (game);
}
void *game_window_init(t_game *game)
{
	size_t	pixels_per_tile;

	pixels_per_tile = 50;
	game->game_window_size = malloc(1 * sizeof(t_point));
	game->game_window_size->x = game->matrix_size->x * pixels_per_tile;
	game->game_window_size->y = game->matrix_size->y * pixels_per_tile;
	game->moves_counter = 0;
	game->mlx = mlx_init(game->game_window_size->x, game->game_window_size->y,
			"Berry Princess Game", true);
	if (game->mlx == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
}

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

int	textures_to_images_init(t_game *game)
{
	mlx_image_t		*image_floor;
	mlx_image_t		*image_tree;
	mlx_image_t		*image_castle_color;
	mlx_image_t		*image_castle_grey;
	mlx_image_t		*image_strawberry;
	mlx_image_t		*image_princess;

	image_floor = malloc(1 * sizeof(mlx_image_t));
	image_floor = mlx_texture_to_image(game->mlx, game->textures[0]);
	if (image_floor == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_tree = mlx_texture_to_image(game->mlx, textures[1]);
	if (image_tree == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_castle_grey = mlx_texture_to_image(game->mlx, textures[2]);
	if (image_castle_grey == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_castle_color = mlx_texture_to_image(game->mlx, textures[3]);
	if (image_castle_color == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_princess = mlx_texture_to_image(game->mlx, textures[4]);
	if (image_princess == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	image_strawberry = mlx_texture_to_image(game->mlx, textures[5]);
	if (image_strawberry == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	
	
	// if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
	// 	return (0);
	// mlx_loop(game->mlx);
	return (1);
}
