/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:01:39 by brappo            #+#    #+#             */
/*   Updated: 2023/11/15 16:16:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(unsigned long n, int base_length)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= base_length;
		length++;
	}
	return (length);
}

static char	*null_char(char *base)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = *base;
	result[1] = '\0';
	return (result);
}

char	*ft_itoa_base(long n, char *base, int length_base, int type)
{
	int				length;
	char			*result;
	unsigned long	u_n;

	if (type == 0)
		u_n = ft_cast_ul(n);
	else if (type == 1)
		u_n = ft_abs(n);
	else
		u_n = ft_cast_pointer(n);
	length = get_length(u_n, length_base);
	if (u_n == 0)
		return (null_char(base));
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	while (u_n != 0)
	{
		result[length-- - 1] = base[u_n % length_base];
		u_n /= length_base;
	}
	return (result);
}
