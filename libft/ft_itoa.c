/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:43:24 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/26 18:24:23 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len += 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_intstr(char *str, long int nbr, int i, int len)
{
	while (len > i)
	{
		str[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			i;
	int			len;
	char		*str;

	nbr = (long int) n;
	len = ft_intlen(n);
	str = malloc((len + 1) * sizeof(char ));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		str[i] = '-';
		i++;
	}
	str = ft_intstr(str, nbr, i, len);
	str[len] = '\0';
	return (str);
}
