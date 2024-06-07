/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:51 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/06 17:58:30 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"	

t_game	*game_init(t_game *game)
{
	size_t			pixels_per_tile;
	// mlx_image_t		*img;

	pixels_per_tile = 50;
	game->game_window_size = malloc(1 * sizeof(t_point));
	game->game_window_size->x = game->matrix_size->x * pixels_per_tile;
	game->game_window_size->y = game->matrix_size->y * pixels_per_tile;
	game->moves_counter = 0;
	game->mlx = mlx_init(game->game_window_size->x, \
	game->game_window_size->y, "Berry Princess Game", true);
	if (game->mlx == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (images_init(game) == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	mlx_loop(game->mlx);
	return (game);
}

int	images_init(t_game *game)
{
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_tree;

	game->images = malloc(5 * sizeof(mlx_image_t));
	if (game->images == NULL)
		return (0);
	texture_floor = mlx_load_png("./textures/floor.png");
	if (texture_floor == NULL)
		return (0);
	game->images[0] = mlx_texture_to_image(game->mlx, texture_floor);
	if (game->images[0] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->images[1] = mlx_load_png("./textures/tree.png");
	if (game->images[1] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->images[2] = mlx_load_png("./textures/strawberry.png");
	if (game->images[2] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->images[3] = mlx_load_png("./textures/castle_grey.png");
	if (game->images[3] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->images[4] = mlx_load_png("./textures/castle_color.png");
	if (game->images[4] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	game->images[5] = mlx_load_png("./textures/princess.png");
	if (game->images[5] == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
	return (1);
}

/* int	load_texture(char *texture_path)
// int	load_texture(t_game *game, char *texture_path)
{
	mlx_texture_t	*texture;
	// mlx_image_t		*img;

	texture = mlx_load_png(texture_path);
	if (texture == NULL)
	{
		ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1);
		return (0);
	}
	// img = mlx_texture_to_image(game->mlx, texture);
	// if (img == NULL)
	// {
	// 	ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1);
	// 	return (0);
	// }
	// if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
	// 	return (0);
	// mlx_loop(game->mlx);
	return (1);
} */
