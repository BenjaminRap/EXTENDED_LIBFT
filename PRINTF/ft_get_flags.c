/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:38:46 by brappo            #+#    #+#             */
/*   Updated: 2023/11/29 15:06:58 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_number(va_list vl, char *str, size_t *i)
{
	int	result;

	if (str[*i] == '*')
	{
		*i = *i + 1;
		result = va_arg(vl, int);
	}
	else
	{
		result = ft_atoi(str + *i);
		while (str[*i] <= '9' && str[*i] >= '0')
			*i = *i + 1;
	}
	return (result);
}

static void	ft_fix_flags(int *flags)
{
	if (flags[WIDTH] < 0)
	{
		flags[WIDTH] = -flags[WIDTH];
		flags[MINUS] = 1;
	}
	if (flags[MINUS])
		flags[ZERO] = 0;
	if (flags[TYPE] == STRING)
	{
		flags[PLUS] = 0;
		flags[SPACE] = 0;
	}
	if (flags[PLUS])
		flags[SPACE] = 0;
	if (flags[TYPE] != HEXA_MIN && flags[TYPE] != HEXA_MAJ)
		flags[HASH] = 0;
	if (flags[PRECISION] > -1)
		flags[ZERO] = 0;
	if (flags[ZERO] && flags[WIDTH] != 0)
	{
		if (flags[PRECISION] < flags[WIDTH])
			flags[PRECISION] = flags[WIDTH];
		flags[WIDTH] = 0;
	}
}

int	*ft_get_flags(va_list vl, char *str, size_t *i)
{
	int	*flags;
	int	arg_type;

	flags = (int *)calloc(8, sizeof(int));
	if (flags == NULL)
		return (NULL);
	*i = *i + 1;
	arg_type = ft_is_in_set(str[*i], "-+ #0");
	while (arg_type != -1)
	{
		flags[arg_type] = 1;
		*i = *i + 1;
		arg_type = ft_is_in_set(str[*i], "-+ #0");
	}
	flags[WIDTH] = ft_get_number(vl, str, i);
	if (str[*i] == '.')
	{
		*i = *i + 1;
		flags[PRECISION] = ft_get_number(vl, str, i);
	}
	else
		flags[6] = -1;
	flags[TYPE] = ft_is_in_set(str[*i], "cspdiuxX%");
	ft_fix_flags(flags);
	return (flags);
}
