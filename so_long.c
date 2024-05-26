/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:16:35 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/26 21:48:36 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char *argv[])
{
	t_map	map;
	mlx_t	*mlx;

	if (argc != 2)
		ft_printf("Invalid input! Pleaser enter a map: ./so_long map.ber");
	else
	{
		map.filepath = argv[1];
		if (check_valid_map_input(map.filepath) == 1)
		{
			if (!(mlx = mlx_init(WIDTH, HEIGHT, "Berry Princess Game", true)))
			{
				puts(mlx_strerror(mlx_errno));
				return (EXIT_FAILURE);
			}
			mlx_loop(mlx);
			mlx_terminate(mlx);
		}
		else
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
