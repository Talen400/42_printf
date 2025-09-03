/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:24:18 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/23 15:13:27 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c_chr;
	char			*str;

	str = (char *) s;
	c_chr = (unsigned char) c;
	while (*str)
	{
		str++;
	}
	while (str >= s)
	{
		if (*str == c_chr)
			return (str);
		str--;
	}
	return ((void *) 0);
}
