/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:09:41 by brappo            #+#    #+#             */
/*   Updated: 2023/11/09 11:55:57 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	len_src;
	unsigned int	len_dest;
	unsigned int	i;

	i = 0;
	len_dest = 0;
	len_src = 0;
	while (dest[len_dest] && len_dest < size)
		len_dest++;
	while (src[len_src])
		len_src++;
	if (size == 0 || len_dest == size)
		return (len_src + len_dest);
	while (src[i] && len_dest + i < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
