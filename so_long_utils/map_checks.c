/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:26:57 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/30 22:20:07 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_filetype(char	*filepath)
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

int	check_valid_map(char *filepath, char **matrix, char *components_array)
{
	if (check_map_rectangle(matrix) == 0)
	{
		ft_printf("Error\nInvalid map! It has to be a rectangle!\n");
		return (0);
	}
	if (check_wall_borders(matrix, filepath) == 0)
	{
		ft_printf("Error\nInvalid map! It has to be sourrounded by walls!\n");
		return (0);
	}
	if (check_map_components(components_array, filepath, matrix) == 0)
	{
		ft_printf("Error\nInvalid components!\n");
		return (0);
	}
	return (1);
}

int	check_valid_input(char *map_path)
{
	char	**map_data;
	char	*components;

	components = "CEP";
	map_data = read_map_file(map_path);
	if (map_data == NULL)
	{
		ft_printf("Error\nReading .ber-file failed!\n");
		return (0);
	}
	if (check_filetype(map_path) == 0)
	{
		ft_printf("Error\nInvalid map file extension! Use .ber-file\n");
		return (0);
	}
	if (check_valid_map(map_path, map_data, components) == 0)
	{
		return (0);
	}
	return (1);
}
