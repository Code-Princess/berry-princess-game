/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:13:13 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/01 15:24:58 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
