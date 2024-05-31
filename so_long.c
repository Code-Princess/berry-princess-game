/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:16:35 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/31 21:58:01 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char *argv[])
{
	mlx_t	*mlx;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of input arguments! \
		Use: ./so_long map.ber\n");
	}
	else
	{
		if (check_valid_input(argv[1]) == 1)
		{
			mlx = mlx_init(WIDTH, HEIGHT, "Berry Princess Game", true);
			if (!(mlx))
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
