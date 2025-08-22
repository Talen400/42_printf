/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:28:17 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/29 17:20:10 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_chr;
	unsigned char	*dest_chr;
	size_t			i;

	if (!dest && !src)
		return ((void *) 0);
	src_chr = (unsigned char *) src;
	dest_chr = (unsigned char *) dest;
	if (dest_chr < src_chr)
	{
		i = 0;
		while (i < n)
		{
			dest_chr[i] = src_chr[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dest_chr[n] = src_chr[n];
	}
	return (dest);
}
