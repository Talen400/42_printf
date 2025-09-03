/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:19:33 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/26 17:06:39 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_sub_ma(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static char	**ft_null(char **str, size_t len)
{
	while (--len > 0)
		free(str[len]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		len;
	char		**str;

	len = ft_count_words(s, c);
	str = malloc((len + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (*s && i < len)
	{
		while (*s == c)
			s++;
		str[i] = ft_sub_ma(s, c);
		if (!str[i])
		{
			return (ft_null(str, i));
		}
		s += ft_strlen(str[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
