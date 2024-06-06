/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_modified.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:33:59 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/05 20:10:30 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_modified(const char *s, int fd)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
}
