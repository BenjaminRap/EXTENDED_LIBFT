/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:24 by brappo            #+#    #+#             */
/*   Updated: 2023/11/14 09:33:56 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, char const *set)
{
	int	len;
	int	i;

	len = ft_strlen((char *)set);
	i = 0;
	while (i < len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen((char *)s1) - 1;
	while (isinset(s1[start], set))
		start++;
	while (isinset(s1[end], set))
		end--;
	if (start > end)
	{
		result = (char *)malloc(sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	return (ft_substr(s1, start, end - start + 1));
}
