/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:07:09 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/28 20:07:35 by llacsivy         ###   ########.fr       */
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
