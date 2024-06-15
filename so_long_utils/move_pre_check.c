/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:38:44 by linda             #+#    #+#             */
/*   Updated: 2024/06/15 14:37:12 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pre_check_wall_up(mlx_instance_t *img_instances, size_t amount_tile_pixels,
		char **matrix)
{
	size_t	idx_x;
	size_t	idx_y;

	idx_x = img_instances[0].x / amount_tile_pixels;
	idx_y = img_instances[0].y / amount_tile_pixels;
	if (matrix[idx_y - 1][idx_x] == '1')
		return (1);
	else
		return (0);
}

int	pre_check_wall_down(mlx_instance_t *img_instances,
						size_t amount_tile_pixels,
						char **matrix)
{
	size_t	idx_x;
	size_t	idx_y;

	idx_x = img_instances[0].x / amount_tile_pixels;
	idx_y = img_instances[0].y / amount_tile_pixels;
	if (matrix[idx_y + 1][idx_x] == '1')
		return (1);
	else
		return (0);
}

int	pre_check_wall_left(mlx_instance_t *img_instances,
						size_t amount_tile_pixels,
						char **matrix)
{
	size_t	idx_x;
	size_t	idx_y;

	idx_x = img_instances[0].x / amount_tile_pixels;
	idx_y = img_instances[0].y / amount_tile_pixels;
	if (matrix[idx_y][idx_x - 1] == '1')
		return (1);
	else
		return (0);
}

int	pre_check_wall_right(mlx_instance_t *img_instances,
							size_t amount_tile_pixels,
							char **matrix)
{
	size_t	idx_x;
	size_t	idx_y;

	idx_x = img_instances[0].x / amount_tile_pixels;
	idx_y = img_instances[0].y / amount_tile_pixels;
	if (matrix[idx_y][idx_x + 1] == '1')
		return (1);
	else
		return (0);
}
