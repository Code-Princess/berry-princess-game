/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:26:57 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/27 20:37:00 by llacsivy         ###   ########.fr       */
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
//  int check_map_rectangle(char **matrix)
// {
// 	size_t i;

// 	i = 0;
// 	while (i < )
// 	{
// 		/* code */
// 	}
	
// } 

int	check_valid_map_input(char *map_path)
{
	char	**map_data;

	if (check_filetype(map_path) == 0)
	{
		ft_printf("Error\n");
		ft_printf("Invalid map file extension!\nPlease enter a .ber-file");
		return (0);
	}
	map_data = read_map_file(map_path);
	if (map_data == NULL)
	{
		ft_printf("Error\n");
		ft_printf("Reading .ber-file failed!\nPlease enter a .ber-file");
		return (0);
	}
	return (1);
}
