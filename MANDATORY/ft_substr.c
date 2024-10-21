/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:50:40 by brappo            #+#    #+#             */
/*   Updated: 2023/11/14 09:31:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned long	i;
	unsigned long	length;

	i = -1;
	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	if (start >= length)
	{
		result = (char *)malloc(sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (start + len >= length)
		len = length - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (++i < len && s[start + i])
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}
