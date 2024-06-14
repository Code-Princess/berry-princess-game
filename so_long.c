/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:16:35 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/15 00:14:12 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

int32_t	main(int argc, char *argv[])
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
			mlx_loop_hook(princess_game->mlx, hook_functions, princess_game);
			mlx_loop(princess_game->mlx);
			mlx_terminate(princess_game->mlx);
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
