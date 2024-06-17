/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:26:57 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/17 16:58:02 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>

char	**read_map_file(char *filepath, t_game *game)
{
	int		fd;
	char	*map_lines;
	char	*next_line;

	map_lines = ft_calloc(1, sizeof(char));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		free(map_lines);
		return (NULL);
	}
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		map_lines = ft_strjoin_mod(map_lines, next_line);
		free(next_line);
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
	}
	game->map_data = ft_split_modified(map_lines, '\n', game);
	free(map_lines);
	return (game->map_data);
}

int	check_map_rectangle(char **matrix)
{
	size_t	matrix_len;
	size_t	x;

	matrix_len = ft_strlen(matrix[0]);
	x = 1;
	while (matrix[x] != NULL)
	{
		if (ft_strlen(matrix[x]) != matrix_len)
			return (0);
		x++;
	}
	return (1);
}

int	check_valid_map(char *components, char **matrix, \
size_t matrix_len, size_t matrix_height)
{
	if (check_map_rectangle(matrix) == 0)
	{
		ft_printf("Error\nInvalid map! It has to be a rectangle!\n");
		return (0);
	}
	if (check_valid_map_elements(components, matrix, \
	matrix_len, matrix_height) == 0)
	{
		ft_printf("Error\nInvalid map elements! Use only: 01CEP\n");
		return (0);
	}
	if (check_valid_component_counts(components, matrix, \
		matrix_len, matrix_height) == 0)
	{
		ft_printf("Error\nInvalid number of components!\n");
		return (0);
	}
	if (check_wall_borders(matrix, matrix_len, matrix_height) == 0)
	{
		ft_printf("Error\nInvalid map! It has to be sourrounded by walls!\n");
		return (0);
	}
	return (1);
}

int	check_valid_input(char *map_path, t_game *game)
{
	char	*valid_map_elements;
	char	*components_to_reach;
	char	**map_data_cpy;

	valid_map_elements = "CEP01";
	components_to_reach = "CEP";
	if (check_valid_filetype(map_path) == 0)
		return (ft_printf("Error\nInvalid map file extension! " \
		"Use .ber-file\n"), 0);
	if (get_map_data(map_path, game) == 0)
		return (0);
	if (check_valid_map(valid_map_elements, \
	game->map_data, game->matrix_size_x, game->matrix_size_y) == 0)
		return (0);
	get_start_position(game);
	map_data_cpy = copy_matrix(game->map_data, game->matrix_size_y);
	if (map_data_cpy == NULL)
		return (0);
	if (check_valid_flood_fill_path(map_data_cpy, \
	game, components_to_reach) == 0)
		return (0);
	free_matrix_entries(map_data_cpy, game->matrix_size_y);
	free(map_data_cpy);
	return (1);
}

int	get_map_data(char *map_path, t_game *game)
{
	game->map_data = read_map_file(map_path, game);
	if (game->map_data == NULL)
		return (ft_printf("Error\nReading .ber-file failed!\n"), 0);
	if (game->map_data[0] == (void *)0)
		return (ft_printf("Error\nYour .ber-file is empty!\n"), 0);
	game->matrix_size_x = ft_strlen(game->map_data[0]);
	game->matrix_size_y = get_row_count(map_path);
	return (1);
}
