/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:16:35 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/16 22:24:40 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	free_princess_game(t_game *game)
{
	free(game->game_window_size);
	free(game->matrix_size);
	// free(game->textures[0]);
	// free(game->textures[1]);
	// free(game->textures[2]);
	// free(game->textures[3]);
	// free(game->textures[4]);
	// free(game->textures[5]);
	// free(game->textures);
}

int	main(int argc, char *argv[])
{
	t_game				*princess_game;

	if (argc != 2)
		ft_printf("Error\nInvalid number of input arguments!" \
		"Use: ./so_long map.ber\n");
	else
	{
		princess_game = malloc(1 * sizeof(t_game));
		if (check_valid_input(argv[1], princess_game) == 1)
		{
			princess_game = game_init(princess_game);
			if (princess_game == NULL)
				return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);
			mlx_key_hook(princess_game->mlx, &hook_functions, princess_game);
			mlx_loop(princess_game->mlx);
			mlx_terminate(princess_game->mlx);
			free_princess_game(princess_game);
		}
		else
		{
			free(princess_game);
			return (1);
		}
	}
	// system("leaks so_long");
	return (0);
}
