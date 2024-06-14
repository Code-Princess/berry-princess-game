/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:38:44 by linda             #+#    #+#             */
/*   Updated: 2024/06/13 19:00:19 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int pre_check_wall_up (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x;
    size_t idx_y;

    idx_x = img_instances[0].x / amount_tile_pixels;
    idx_y = img_instances[0].y / amount_tile_pixels;
printf ("idx_x: %ld, idx_y: %ld\n", idx_x, idx_y);
    if (matrix[idx_y - 1][idx_x] == '1')
    {
printf ("matrix[idx_y - 1][idx_x]: %c\n", matrix[idx_y - 1][idx_x]);
        return (1);
    }
        
    else
        return (0);
}

int pre_check_wall_down (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x;
    size_t idx_y;

    idx_x = img_instances[0].x / amount_tile_pixels;
    idx_y = img_instances[0].y / amount_tile_pixels;
printf ("idx_x: %ld, idx_y: %ld\n", idx_x, idx_y);
    if (matrix[idx_y + 1][idx_x] == '1')
{
printf ("matrix[idx_y + 1][idx_x]: %c\n", matrix[idx_y + 1][idx_x]);
        return (1);
}    

    else
        return (0);
}

int pre_check_wall_left (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x;
    size_t idx_y;

    idx_x = img_instances[0].x / amount_tile_pixels;
    idx_y = img_instances[0].y / amount_tile_pixels;
printf ("idx_x: %ld, idx_y: %ld\n", idx_x, idx_y);
printf ("idx_x - 1: %ld\n", idx_x - 1);
printf ("matrix[1][2]: %c\n", matrix[1][2]);
printf ("matrix[1][1]: %c\n", matrix[1][1]);
    if (matrix[idx_y][idx_x - 1] == '1')
    {


        return (1);
    }
        
    else
        return (0);
}

int pre_check_wall_right (mlx_instance_t *img_instances, size_t amount_tile_pixels, char **matrix)
{
    size_t idx_x;
    size_t idx_y;

    idx_x = img_instances[0].x / amount_tile_pixels;
    idx_y = img_instances[0].y / amount_tile_pixels;
printf ("idx_x: %ld, idx_y: %ld\n", idx_x, idx_y);
    if (matrix[idx_y][idx_x + 1] == '1')
    {
printf ("matrix[idx_y][idx_x + 1]: %c\n", matrix[idx_y][idx_x + 1]);
        return (1);
    }
        
    else
        return (0);
    
}