/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:40:55 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/31 13:11:09 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc_modified(size_t count, size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(count * size);
	if (!tmp)
	{
		return (free(tmp), tmp = NULL, NULL);
	}
	ft_bzero(tmp, count * size);
	return (tmp);
}

int	ft_strlen_modified(const char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		return (len);
	}
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin_modified(char *s1, char *s2, int s2_len)
{
	unsigned int	len;
	char			*joinedstr;
	unsigned int	str_idx;
	int				s2_idx;

	len = ft_strlen_modified(s1) + s2_len;
	str_idx = 0;
	s2_idx = 0;
	joinedstr = (char *)ft_calloc_modified(len + 1, sizeof(char));
	if (!joinedstr)
		return (NULL);
	while (s1 && s1[str_idx] != '\0')
	{
		joinedstr[str_idx] = s1[str_idx];
		str_idx++;
	}
	while (s2_idx < s2_len)
	{
		joinedstr[str_idx] = *s2;
		s2++;
		str_idx++;
		s2_idx++;
	}
	joinedstr[str_idx] = '\0';
	return (free(s1), s1 = NULL, joinedstr);
}
