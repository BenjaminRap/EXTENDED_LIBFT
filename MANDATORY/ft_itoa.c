/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:01:39 by brappo            #+#    #+#             */
/*   Updated: 2023/11/10 15:27:49 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*null_char(void)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	result;

	if (n < 0)
		result = n * -1;
	else
		result = n;
	return (result);
}

static char	*setup_result(int n, int length)
{
	char	*result;

	if (n < 0)
	{
		result = (char *)malloc((length + 2) * sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '-';
	}
	else
		result = (char *)malloc((length + 1) * sizeof(char));
	return (result);
}

char	*ft_itoa(int n)
{
	int				length;
	char			*result;
	unsigned int	u_n;

	u_n = ft_abs(n);
	length = get_length(n);
	if (n == 0)
		return (null_char());
	result = setup_result(n, length);
	if (n < 0)
		length++;
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	while (u_n != 0)
	{
		result[length-- - 1] = u_n % 10 + 48;
		u_n /= 10;
	}
	return (result);
}
