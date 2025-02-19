/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_modified.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:19:07 by llacsivy          #+#    #+#             */
/*   Updated: 2024/06/18 16:57:40 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../so_long.h"

static int	word_nr(char const *s, char c);
static char	*copy_a_word(char *s, int start, int end);
static void	*free_memory(char **strings, int count);
static void	init_vars(size_t *i, int *result_index, int *word_start_index);

char	**ft_split_modified(char *s, char c, t_game *game)
{
	size_t	i;
	int		result_index;
	int		word_start_index;

	init_vars(&i, &result_index, &word_start_index);
	game->map_data = ft_calloc((word_nr(s, c) + 1), sizeof(char *));
	if (game->map_data == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start_index < 0)
			word_start_index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_start_index >= 0)
		{
			game->map_data[result_index] = copy_a_word(s, word_start_index, i);
			if (game->map_data[result_index] == NULL)
				return (free_memory(game->map_data, result_index));
			word_start_index = -1;
			result_index++;
		}
		i++;
	}
	return (game->map_data);
}

static void	init_vars(size_t *i, int *result_index, int *word_start_index)
{
	*i = 0;
	*result_index = 0;
	*word_start_index = -1;
}

static int	word_nr(char const *s, char c)
{
	int	nr;
	int	isseparator;

	nr = 0;
	isseparator = 0;
	while (*s != '\0')
	{
		if (*s != c && isseparator == 0)
		{
			isseparator = 1;
			nr++;
		}
		else if (*s == c)
			isseparator = 0;
		s++;
	}
	return (nr);
}

static char	*copy_a_word(char *s, int start, int end)
{
	char	*dest_word;
	int		i;

	i = 0;
	dest_word = malloc(end - start + 1);
	if (dest_word == NULL)
		return (NULL);
	while (start < end)
	{
		dest_word[i] = s[start];
		start++;
		i++;
	}
	dest_word[i] = '\0';
	return (dest_word);
}

static void	*free_memory(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}
