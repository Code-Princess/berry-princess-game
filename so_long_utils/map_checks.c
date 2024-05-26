/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:26:57 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/26 22:11:09 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_filetype(char	*filename)
{
	ft_printf("%s\n", filename);
	return (0);
}

int	check_valid_map_input(char *map_path)
{
	if (check_filetype("map_01.ber") == 0)
	{
		ft_printf("%s\n", map_path);
		return (0);
	}
	return (1);
}
