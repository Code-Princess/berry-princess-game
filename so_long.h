/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:52:46 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/18 00:08:17 by llacsivy         ###   ########.fr       */
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
	size_t			matrix_size_x;
	size_t			matrix_size_y;
	t_point			*game_window_size;
	size_t			pixels_per_tile;
	int				moves_counter;
	mlx_texture_t	**textures;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_tree;
	mlx_image_t		*image_castle_color;
	mlx_image_t		*image_castle_grey;
	mlx_image_t		*image_strawberry;
	mlx_image_t		*image_princess;
	int				collected_berries_counter;
	size_t			start_pos_x;
	size_t			start_pos_y;
	id_t			can_move;
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
void		flood_fill(char **tab, t_game *game);
void		fill(char **tab, t_game *game,
				char *to_fill);
int			check_valid_flood_fill_path(char **matrix,
				t_game *game, char *components_to_reach);
void		get_start_position(t_game *game);
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
void		escape_close_window(mlx_key_data_t keydata, \
							void *game_parameter);
int			get_map_data(char *map_path, t_game *game);
void		print_moves_counter(void *game_parameter);
void		collect_berries(mlx_key_data_t keydata, void *game_parameter);
void		exit_castle(void *game_parameter);
void		free_matrix_entries(char **matrix, \
			size_t matrix_height);
char		*ft_strjoin_mod(char *s1, char *s2);
void		free_princess_game(t_game *game);

#endif
