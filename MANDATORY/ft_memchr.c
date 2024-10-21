/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:51:27 by brappo            #+#    #+#             */
/*   Updated: 2023/11/10 09:35:08 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*char_s;

	i = 0;
	char_s = (char *)s;
	while (i < n)
	{
		if (char_s[i] == (char)c)
			return ((void *)char_s + i);
		i++;
	}
	return (NULL);
}
