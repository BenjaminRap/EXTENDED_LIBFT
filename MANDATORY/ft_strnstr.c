/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:12:40 by brappo            #+#    #+#             */
/*   Updated: 2024/01/19 18:40:28 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && i < ft_strlen((char *)big))
	{
		j = 0;
		while (j < len - i && j < ft_strlen((char *)little))
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
