/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:41:07 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/17 23:15:43 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>

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

char	**copy_matrix(char **matrix, size_t height)
{
	char	**matrix_copied;
	size_t	y;

	matrix_copied = malloc(height * sizeof(char *));
	if (matrix_copied == NULL)
	{
		return (NULL);
	}
	y = 0;
	while (y < height)
	{
		matrix_copied[y] = ft_strdup(matrix[y]);
		y++;
	}
	return (matrix_copied);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*joinedstr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joinedstr = (char *)malloc(s1_len + s2_len + 1);
	if (joinedstr == 0)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		joinedstr[i++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		joinedstr[i++] = *s2;
		s2++;
	}
	joinedstr[i] = '\0';
	return (joinedstr);
}
