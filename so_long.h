/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:52:46 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/01 20:45:18 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef WIDTH
#  define WIDTH 512
# endif
# ifndef HEIGHT
#  define HEIGHT 512
# endif

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

int		check_valid_input(char *map_path);
int		check_valid_filetype(char	*filepath);
char	**read_map_file(char *filepath);
int		check_valid_map(char *components, char **matrix, \
		size_t matrix_len, size_t matrix_height);
int		check_map_rectangle(char **matrix);
int		check_wall_borders(char **matrix, \
		size_t matrix_len, size_t matrix_height);
size_t	get_row_count(char *filepath);
int		count_components(char c, char **matrix, size_t length, size_t width);
int		check_valid_component_counts(char *components, char **matrix, \
		size_t map_len, size_t map_height);
int		check_valid_map_elements(char *components, char **matrix, \
		size_t matrix_len, size_t matrix_height);
void	flood_fill(char **tab, t_point *size, t_point *begin);
void	fill(char **tab, t_point *size, t_point *current_point, char *to_fill);
int		check_valid_flood_fill_path(char **matrix, t_point *matrix_size, \
		t_point *begin_position, char *components_to_reach);
t_point	*get_start_position(char **matrix, size_t matrix_len, \
		size_t matrix_height);
void	write_matrix(char **matrix, size_t height);
int		char_in_set(char c, char *set);

#endif