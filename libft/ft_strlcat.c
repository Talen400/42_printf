/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:29:24 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/31 11:08:45 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	len = 0;
	if (dst_len >= size)
		return (src_len + size);
	while (src[len] && (dst_len + len) < size - 1)
	{
		dst[dst_len + len] = src[len];
		len++;
	}
	dst[dst_len + len] = '\0';
	return (src_len + dst_len);
}
