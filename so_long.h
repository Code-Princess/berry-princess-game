/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:52:46 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/29 22:42:01 by llacsivy         ###   ########.fr       */
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

int		check_valid_map_input(char *map_filename);
int		check_filetype(char	*filepath);
char	**read_map_file(char *filepath);
int		check_map_rectangle(char **matrix);
int		check_wall_borders(char **matrix, char *filepath);
size_t	get_row_count(char *filepath);
int		check_map_components(char *filename, char **matrix, char component);

#endif