/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:41:07 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/01 15:57:41 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
