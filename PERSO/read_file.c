/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:21:49 by brappo            #+#    #+#             */
/*   Updated: 2024/01/25 11:40:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_file(int fd, char **result)
{
	int		rd;
	char	buffer[100];
	char	*temp;

	rd = read(fd, buffer, 99);
	if (rd == -1)
		return (1);
	buffer[rd] = '\0';
	*result = ft_strjoin("", buffer);
	while (rd > 0)
	{
		if (*result == NULL)
			return (0);
		rd = read(fd, buffer, 99);
		if (rd == -1)
			return (free(*result), 1);
		buffer[rd] = '\0';
		temp = ft_strjoin(*result, buffer);
		free(*result);
		*result = temp;
	}
	return (1);
}
