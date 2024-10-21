/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:23 by brappo            #+#    #+#             */
/*   Updated: 2024/01/21 23:51:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_type(long to_print, int type)
{
	if (type == 1)
	{
		if ((char *)to_print == NULL)
			return (ft_strdup("null"));
		return (ft_strdup((char *)to_print));
	}
	if (type == 6)
		return (ft_itoa_base((long)to_print, "0123456789abcdef", 16, 0));
	if (type == 2)
	{
		if ((unsigned long)to_print == 0)
			return (ft_strdup("(nil)"));
		return (ft_itoa_base(to_print, "0123456789abcdef", 16, 2));
	}
	if (type >= 3 && type <= 4)
		return (ft_itoa_base((int)to_print, "0123456789", 10, 1));
	if (type == 5)
		return (ft_itoa_base(to_print, "0123456789", 10, 0));
	if (type == 7)
		return (ft_itoa_base(to_print, "0123456789ABCDEF", 16, 0));
	return (ft_strdup("!"));
}

static int	ft_print_char(long c, char **result, int *flags)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 1;
	*result = (char *)malloc((flags[WIDTH] + 1) * sizeof(char));
	if (*result == NULL)
		return (-1);
	if (flags[MINUS])
		(*result)[i++] = (char)c;
	while (j++ < flags[WIDTH] - 1)
	{
		if (flags[ZERO])
			(*result)[i++] = '0';
		else
			(*result)[i++] = ' ';
	}
	if (!flags[MINUS])
		(*result)[i] = (char)c;
	if (flags[WIDTH] > 0)
		count = flags[WIDTH];
	return (count);
}

static char	*ft_get_prefix(long nbr, int *flags)
{
	if (flags[TYPE] == POINTER)
	{
		if ((unsigned long)nbr <= 0)
			return ("");
		return ("0x");
	}
	if (flags[HASH] && ft_cast_ul(nbr) != 0)
	{
		if (flags[TYPE] == HEXA_MIN)
			return ("0x");
		return ("0X");
	}
	if ((int)nbr < 0 && (flags[TYPE] == DECIMAL || flags[TYPE] == INTEGER))
		return ("-");
	if (flags[PLUS])
		return ("+");
	if (flags[SPACE])
		return (" ");
	return ("");
}

int	ft_print_args(long nbr, char **result, int *flags)
{
	char	*temp;

	if (flags == NULL)
		return (-1);
	if (flags[TYPE] == CHAR)
		return (ft_print_char(nbr, result, flags));
	if (flags[PRECISION] == 0 && (unsigned long)nbr == 0
		&& flags[TYPE] != POINTER)
		*result = ft_strdup("");
	else
		*result = ft_itoa_type(nbr, flags[TYPE]);
	if (flags[TYPE] == STRING)
		*result = ft_precision(*result, flags[PRECISION], nbr);
	else if (!(flags[TYPE] >= UNSIGNED && flags[TYPE] <= HEXA_MAJ))
		*result = ft_padding_left(
				flags[PRECISION] - (flags[ZERO] * (int)nbr < 0), *result, '0');
	else
		*result = ft_padding_left(flags[PRECISION], *result, '0');
	temp = *result;
	*result = ft_strjoin(ft_get_prefix(nbr, flags), *result);
	free(temp);
	ft_padding(flags, result);
	return (ft_strlen(*result));
}
