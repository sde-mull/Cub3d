/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:07:38 by sde-mull          #+#    #+#             */
/*   Updated: 2021/10/30 21:07:38 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int		index;
	int		word_counter;
	char	is_word;

	index = 0;
	word_counter = 0;
	is_word = 'y';
	while (s[index] != '\0')
	{
		if (s[index] != c && is_word == 'y')
		{
			word_counter = word_counter + 1;
			is_word = 'n';
		}
		else if (s[index] == c && is_word == 'n')
			is_word = 'y';
		index++;
	}
	return (word_counter);
}

static int	ft_len_word(char const *s, char c)
{
	int	index;

	index = 0;
	while (s[index] != '\0' && s[index] != c)
		index++;
	return (index);
}

static char	**ft_fill(int number_words, char **ptr, char c, char *s)
{
	int		index;
	int		sep_index;
	int		len;

	index = 0;
	sep_index = 0;
	while (sep_index < number_words)
	{
		index = 0;
		while (s[index] == c && s[index] != '\0')
			index++;
		s = (s + index);
		len = ft_len_word((char *)s, c);
		ptr[sep_index] = ft_substr((char *)s, 0, len);
		if (ptr[sep_index] == 0)
			return (NULL);
		s = (s + len);
		sep_index++;
	}
	ptr[sep_index] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		nbr_of_words;

	if (!s)
		return (NULL);
	nbr_of_words = ft_words((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (nbr_of_words + 1));
	if (str == 0)
		return (NULL);
	str = ft_fill(nbr_of_words, str, c, (char *)s);
	return (str);
}
