/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:42:38 by brappo            #+#    #+#             */
/*   Updated: 2024/01/19 20:04:15 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		length;
	char	*result;
	int		i;

	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	i = 0;
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i <= length)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
