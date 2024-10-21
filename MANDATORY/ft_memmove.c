/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:33:31 by brappo            #+#    #+#             */
/*   Updated: 2023/11/10 15:12:58 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;
	size_t	i;

	i = -1;
	char_dest = (char *)dest;
	char_src = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest - src < 0)
		while (++i < n)
			char_dest[i] = char_src[i];
	else
		while (++i < n)
			char_dest[n - i - 1] = char_src[n - i - 1];
	return (char_dest);
}
