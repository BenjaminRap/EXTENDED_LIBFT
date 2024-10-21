/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:01:36 by brappo            #+#    #+#             */
/*   Updated: 2024/01/21 18:59:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	read_arg(va_list vl, size_t *i, const char *n)
{
	char	*arg;
	int		*flags;
	long	length;

	length = 1;
	if (n[*i] == '%')
	{
		flags = ft_get_flags(vl, (char *)n, i);
		if (flags != NULL && flags[7] == -1)
			length = -1;
		else if (flags != NULL && flags[7] == 8)
		{
			arg = ft_strdup("%");
			length = 1;
		}
		else
			length = ft_print_args(va_arg(vl, long), &arg, flags);
		free(flags);
		if (length == -1)
			return (free(arg), -1);
		show_string(arg, &length);
	}
	else
		ft_putchar(n[*i]);
	return (length);
}

int	ft_printf(const char *n, ...)
{
	va_list	vl;
	size_t	i;
	size_t	count;
	size_t	length;
	int		rd;

	if (n == NULL)
		return (-1);
	va_start(vl, n);
	count = 0;
	length = ft_strlen((char *)n);
	i = 0;
	while (i < length)
	{
		rd = read_arg(vl, &i, n);
		if (rd == -1)
			return (-1);
		count += rd;
		i++;
	}
	va_end(vl);
	return (count);
}
