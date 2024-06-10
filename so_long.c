/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:16:35 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/10 18:09:14 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

static mlx_image_t	*image;

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int32_t	main(int argc, char *argv[])
{
	t_game				*princess_game;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of input arguments! \
		Use: ./so_long map.ber\n");
	}
	else
	{
		princess_game = malloc(1 * sizeof(t_game));
		if (check_valid_input(argv[1], princess_game) == 1)
		{
			princess_game = game_init(princess_game);
			if (princess_game == NULL)
				return (ft_putstr_fd_modified(mlx_strerror(mlx_errno), 1), 0);

			mlx_loop(princess_game->mlx);
			mlx_terminate(princess_game->mlx);
		}
		else
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
