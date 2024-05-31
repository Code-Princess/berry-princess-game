/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:52:46 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/31 17:09:56 by llacsivy         ###   ########.fr       */
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

#endif