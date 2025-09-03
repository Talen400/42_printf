/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:56:27 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/25 17:12:28 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		right;
	int		left;
	int		len;
	char	*str;

	right = 0;
	while (ft_strchr(set, s1[right]) != NULL)
		right++;
	len = ft_strlen(s1);
	left = len - 1;
	while (left >= right && ft_strrchr(set, s1[left]) != NULL)
		left--;
	if (left < right)
		left = right - 1;
	str = malloc((left - right + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + right, left - right + 2);
	return (str);
}
