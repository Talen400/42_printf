/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:03:56 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/23 15:08:42 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c_chr;

	str = (unsigned char *) s;
	c_chr = (unsigned char ) c;
	i = 0;
	while (i < n)
	{
		if (*str == c_chr)
			return ((void *)(str));
		str++;
		i++;
	}
	return ((void *) 0);
}
