/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:16:35 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/04 20:54:16 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

static mlx_image_t* image;

void ft_hook(void* param)
{
	mlx_t* mlx = param;

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
	
	t_game *princess_game;
	
	princess_game = malloc(1 * sizeof(t_game));
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of input arguments! \
		Use: ./so_long map.ber\n");
	}
	else
	{
		if (check_valid_input(argv[1], princess_game) == 1)
		{
			princess_game->mlx = mlx_init(WIDTH, HEIGHT, "Berry Princess Game", true);
			if (!(princess_game->mlx))
			{
				puts(mlx_strerror(mlx_errno));
				return (EXIT_FAILURE);
			}
			
// mlx_texture_t* texture = mlx_load_png("textures/princess.png");

// mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	
// mlx_image_to_window(mlx, img, 0, 0);
	
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
