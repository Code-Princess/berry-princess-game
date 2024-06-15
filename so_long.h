/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:52:46 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/15 13:12:51 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}			t_point;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map_data;
	t_point			*matrix_size;
	t_point			*game_window_size;
	size_t			pixels_per_tile;
	size_t			moves_counter;
	mlx_texture_t	**textures;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_tree;
	mlx_image_t		*image_castle_color;
	mlx_image_t		*image_castle_grey;
	mlx_image_t		*image_strawberry;
	mlx_image_t		*image_princess;
}			t_game;

int			check_valid_input(char *map_path, t_game *game);
int			check_valid_filetype(char *filepath);
char		**read_map_file(char *filepath, t_game *game);
int			check_valid_map(char *components, char **matrix, size_t matrix_len,
				size_t matrix_height);
int			check_map_rectangle(char **matrix);
int			check_wall_borders(char **matrix,
				size_t matrix_len, size_t matrix_height);
size_t		get_row_count(char *filepath);
int			count_components(char c, char **matrix, size_t length,
				size_t width);
int			check_valid_component_counts(char *components, char **matrix,
				size_t map_len, size_t map_height);
int			check_valid_map_elements(char *components, char **matrix,
				size_t matrix_len, size_t matrix_height);
void		flood_fill(char **tab, t_point *size, t_point *begin);
void		fill(char **tab, t_point *size, t_point *current_point,
				char *to_fill);
int			check_valid_flood_fill_path(char **matrix, t_point *matrix_size,
				t_point *begin_position, char *components_to_reach);
t_point		*get_start_position(char **matrix, size_t matrix_len,
				size_t matrix_height);
void		write_matrix(char **matrix, size_t height);
int			char_in_set(char c, char *set);
t_game		*game_init(t_game *game);
int			gamefield_textures_init(t_game *game);
t_game		*game_window_init(t_game *game);
int			gamefield_textures_to_images_init(t_game *game);
void		*gamefield_init(t_game *game);
int			set_gamefield_floor(t_game *game, mlx_image_t *img);
int			set_images_on_gamefield(t_game *game, mlx_image_t *img, char c);
char		**copy_matrix(char **matrix, size_t height);
void		move_up_down_princess_hooks(mlx_key_data_t keydata, \
			void *game_parameter);
void		move_left_right_princess_hooks(mlx_key_data_t keydata, \
			void *game_parameter);
void		hook_functions(mlx_key_data_t keydata, void *game_parameter);
int			pre_check_wall_up(mlx_instance_t *img_instances, \
				size_t amount_tile_pixels, char **matrix);
int			pre_check_wall_down(mlx_instance_t	*img_instances, \
				size_t amount_tile_pixels, char	**matrix);
int			pre_check_wall_left(mlx_instance_t *img_instances, \
				size_t amount_tile_pixels, char **matrix);
int			pre_check_wall_right(mlx_instance_t *img_instances, \
				size_t amount_tile_pixels, char **matrix);
void		escape_close_window(void *game_parameter);
int			get_map_data(char *map_path, t_game *game);

#endif
