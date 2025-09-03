/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:13:15 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/29 17:18:41 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_chr;
	unsigned char	*src_chr;

	if (!dest && !src)
		return ((void *) 0);
	src_chr = (unsigned char *) src;
	dest_chr = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		dest_chr[i] = src_chr[i];
		i++;
	}
	return (dest);
}
