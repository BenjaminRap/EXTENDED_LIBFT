/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:13:42 by brappo            #+#    #+#             */
/*   Updated: 2024/01/21 19:34:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_padding_left(int width, char *src, char c)
{
	int		length;
	char	*result;
	int		i;

	if (src == NULL)
		return (NULL);
	length = ft_strlen(src);
	i = -1;
	if (length > width)
		width = length;
	result = (char *)malloc((width + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (++i < width - length)
		result[i] = c;
	while (i < width)
	{
		result[i] = src[i - width + length];
		i++;
	}
	result[i] = '\0';
	free(src);
	return (result);
}

char	*ft_padding_right(int width, char *src, char c)
{
	int		length;
	char	*result;
	int		i;

	if (src == NULL)
		return (NULL);
	length = ft_strlen(src);
	i = -1;
	if (length > width)
		width = length;
	result = (char *)malloc((width + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (++i < length)
		result[i] = src[i];
	while (i < width)
	{
		result[i] = c;
		i++;
	}
	result[i] = '\0';
	free(src);
	return (result);
}

void	ft_padding(int *flags, char **result)
{
	if (flags[MINUS])
		*result = ft_padding_right(flags[WIDTH], *result, ' ');
	else
		*result = ft_padding_left(flags[WIDTH], *result, ' ');
}
