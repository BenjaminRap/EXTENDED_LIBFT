/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:23:12 by brappo            #+#    #+#             */
/*   Updated: 2023/11/10 13:21:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		length;
	int		i;
	char	*result;

	if (f == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	i = 0;
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[length] = '\0';
	return (result);
}
