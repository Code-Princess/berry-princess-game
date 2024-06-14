/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:38:44 by linda             #+#    #+#             */
/*   Updated: 2024/06/14 18:43:58 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int pre_check_wall_up (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x_1;
    size_t idx_y_1;

    idx_x_1 = img_instances[0].x / amount_tile_pixels;
    idx_y_1 = img_instances[0].y / amount_tile_pixels;
    if (matrix[idx_y_1 - 1][idx_x_1] == '1')
        return (1);
    else
        return (0);
}

int pre_check_wall_down (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x_1;
    size_t idx_y_1;
    
    idx_x_1 = img_instances[0].x / amount_tile_pixels;
    idx_y_1 = img_instances[0].y / amount_tile_pixels;
    if (matrix[idx_y_1 + 1][idx_x_1] == '1')
        return (1);
    else
        return (0);
}

int pre_check_wall_left (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x_1;
    size_t idx_y_1;

    idx_x_1 = img_instances[0].x / amount_tile_pixels;
    idx_y_1 = img_instances[0].y / amount_tile_pixels;
    if (matrix[idx_y_1][idx_x_1 - 1] == '1')
        return (1);
    else
        return (0);
}

int pre_check_wall_right (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x_1;
    size_t idx_y_1;
    
    idx_x_1 = img_instances[0].x / amount_tile_pixels;
    idx_y_1 = img_instances[0].y / amount_tile_pixels;
    if (matrix[idx_y_1][idx_x_1 + 1] == '1')
        return (1);
    else
        return (0);
    
}