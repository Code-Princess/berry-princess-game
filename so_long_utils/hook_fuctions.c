/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fuctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:56:24 by linda             #+#    #+#             */
/*   Updated: 2024/06/12 14:10:03 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void escape_close_window(void *game_parameter)
{
    t_game *game = game_parameter;
    
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) == 1)
        mlx_close_window(game->mlx);
}

void move_princess_hooks(void *game_parameter)
{
    t_game *game = game_parameter;
    size_t move_step_up_down;
    size_t move_step_left_right;
    
    move_step_up_down = game->pixels_per_tile / 15;
    move_step_left_right = game->pixels_per_tile / 10;
    if (mlx_is_key_down(game->mlx, MLX_KEY_UP) == 1 || mlx_is_key_down(game->mlx, MLX_KEY_W) == 1)
       if (pre_check_wall_up (game->image_princess->instances, game->pixels_per_tile, game->map_data) == 0)
            game->image_princess->instances[0].y -= move_step_up_down; 
    if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) == 1 || mlx_is_key_down(game->mlx, MLX_KEY_S) == 1)
    {
       if (pre_check_wall_down (game->image_princess->instances, game->pixels_per_tile, game->map_data) == 0)
            game->image_princess->instances[0].y += move_step_up_down; 
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) == 1 || mlx_is_key_down(game->mlx, MLX_KEY_A) == 1)
    {
       if (pre_check_wall_left (game->image_princess->instances, game->pixels_per_tile, game->map_data) == 0)
            game->image_princess->instances[0].x -= move_step_left_right; 
    }
     if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) == 1 || mlx_is_key_down(game->mlx, MLX_KEY_D) == 1)
    {
       if (pre_check_wall_right (game->image_princess->instances, game->pixels_per_tile, game->map_data) == 0)
            game->image_princess->instances[0].x += move_step_left_right; 
    }
    return ;
}

void hook_functions(void *game_parameter)
{
    escape_close_window(game_parameter);
    move_princess_hooks(game_parameter);
    return ;
}