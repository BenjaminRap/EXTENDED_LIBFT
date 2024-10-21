/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:06:55 by brappo            #+#    #+#             */
/*   Updated: 2023/11/14 09:28:39 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] && str[i] != c)
			i++;
		if (i != 0)
			count++;
	}
	return (count);
}

static char	*copy(char *src, int start, int end)
{
	int		i;
	char	*sub;

	i = 0;
	sub = (char *)malloc((end - start + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (start < end)
	{
		sub[i] = src[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static void	*free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

static char	**sub_string(char **result, char *str, char c)
{
	int		start;
	int		end;
	int		count;
	char	*sub;

	count = 0;
	end = 0;
	while (str[end])
	{
		start = end;
		while (str[start] == c)
			start++;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		if (end - start > 0)
		{
			sub = copy(str, start, end);
			result[count] = sub;
			if (sub == NULL)
				return (free_strings(result));
			count++;
		}
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (s == NULL)
		return (NULL);
	count = count_words((char *)s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = sub_string(result, (char *)s, c);
	if (result == NULL)
		return (NULL);
	result[count] = 0;
	return (result);
}
