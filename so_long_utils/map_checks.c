/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:26:57 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/01 20:45:49 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_valid_filetype(char	*filepath)
{
	size_t	i;

	i = ft_strlen(filepath) - 1;
	if (filepath[i - 3] == '.' && filepath[i - 2] == 'b'
		&& filepath[i - 1] == 'e' && filepath[i] == 'r')
	{
		return (1);
	}
	else
		return (0);
}

char	**read_map_file(char *filepath)
{
	char	**map_data;
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
		map_lines = ft_strjoin(map_lines, next_line);
		free(next_line);
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
	}
	map_data = ft_split(map_lines, '\n');
	free(map_lines);
	return (map_data);
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

int	check_valid_input(char *map_path)
{
	char	**map_data;
	char	*valid_map_elements;
	t_point	*matrix_size;
	t_point	*start_position;
	char	*components_to_reach;

	valid_map_elements = "CEP01";
	components_to_reach = "CEP";
	if (check_valid_filetype(map_path) == 0)
		return (ft_printf("Error\nInvalid map file extension! \
		Use .ber-file\n"), 0);
	map_data = read_map_file(map_path);
	if (map_data == NULL)
		return (ft_printf("Error\nReading .ber-file failed!\n"), 0);
	matrix_size = malloc(1 * sizeof(t_point));
	matrix_size->x = ft_strlen(map_data[0]);
	matrix_size->y = get_row_count(map_path);
	if (check_valid_map(valid_map_elements, \
	map_data, matrix_size->x, matrix_size->y) == 0)
		return (0);
	start_position = get_start_position(map_data, matrix_size->x, \
	matrix_size->y);
	if (check_valid_flood_fill_path(map_data, matrix_size, start_position, components_to_reach) == 0)
		return (0);
	return (1);
}
