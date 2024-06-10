/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:51 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/10 18:21:26 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

t_game	*game_init(t_game *game)
{
	if (game_window_init(game) == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	if (gamefield_init(game) == 0)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	mlx_loop(game->mlx);
	return (game);
}

t_game	*game_window_init(t_game *game)
{
	game->pixels_per_tile = 50;
	game->game_window_size = malloc(1 * sizeof(t_point));
	game->game_window_size->x = game->matrix_size->x * game->pixels_per_tile;
	game->game_window_size->y = (game->matrix_size->y + 1) * game->pixels_per_tile;
	game->moves_counter = 0;
	game->mlx = mlx_init(game->game_window_size->x, game->game_window_size->y,
			"Berry-Princess-Game", true);
	if (game->mlx == NULL)
		return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), NULL);
	return (game);
}
