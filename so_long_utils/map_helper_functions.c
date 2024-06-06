/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:41:07 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/06 17:58:30 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>

size_t	get_row_count(char *filepath)
{
	size_t	count;
	int		fd;
	char	*next_line;

	count = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	next_line = get_next_line(fd);
	count++;
	while (next_line != NULL)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
	}
	return (count);
}

int	char_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	write_matrix(char **matrix, size_t height)
{
	size_t	y;

	y = 0;
	while (y < height)
	{
		ft_putendl_fd(matrix[y], 1);
		y++;
	}
}
