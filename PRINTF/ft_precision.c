/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:09:51 by brappo            #+#    #+#             */
/*   Updated: 2023/11/15 17:20:46 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cpy(char **result, int precision, int length, char *str)
{
	int	i;

	i = 0;
	while (i < precision && i < length)
	{
		(*result)[i] = str[i];
		i++;
	}
	(*result)[i] = '\0';
}

char	*ft_precision(char *str, int precision, long nbr)
{
	int		length;
	char	*result;

	if (str == NULL)
		return (NULL);
	if (precision <= -1)
		return (str);
	length = ft_strlen(str);
	if ((char *)nbr == NULL && precision < length)
	{
		free(str);
		return (ft_strdup(""));
	}
	if (precision > length)
		result = (char *)malloc((length + 1) * sizeof(char));
	else
		result = (char *)malloc((precision + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	cpy(&result, precision, length, str);
	free(str);
	return (result);
}
