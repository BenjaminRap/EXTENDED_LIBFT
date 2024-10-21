/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:09:52 by marvin            #+#    #+#             */
/*   Updated: 2024/01/23 12:13:15 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_before_char(char *str, char c)
{
	size_t	length;
	size_t	i;
	char	*result;

	length = 0;
	i = 0;
	while (str[length] && str[length] != c)
		length++;
	if (str[length] == '\n')
		length++;
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_after_char(char *str, char c)
{
	size_t	length;
	size_t	start;
	size_t	i;
	char	*result;

	start = 0;
	i = -1;
	length = 0;
	while (str[start] && str[start] != c)
		start++;
	if (str[start] == '\n')
		start++;
	while (str[start + length])
		length++;
	if (!length)
		return (NULL);
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (++i < length)
		result[i] = str[start + i];
	result[i] = '\0';
	return (result);
}

void	check_read_error(int rd, char **result, char	**content)
{
	if (rd == -1)
	{
		if (*content)
			free(*content);
		*result = NULL;
	}
	else
		*result = *content;
}

int	get_next_linebreak(t_fdlist *current, char **temp, t_fdlist **lst,
		char **result)
{
	int		rd;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (0);
	while (ft_strchr(current->content, '\n') == NULL)
	{
		rd = read(current->fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
		{
			check_read_error(rd, result, &(current->content));
			fd_lstremove(lst, current->fd);
			free(buffer);
			return (0);
		}
		*temp = ft_strnjoin(current->content, buffer, rd);
		free(current->content);
		current->content = *temp;
	}
	free(buffer);
	*result = get_before_char(current->content, '\n');
	return (1);
}

char	*get_next_line(int fd)
{
	char			*result;
	char			*temp;
	static t_fdlist	*lst;
	t_fdlist		*current;

	result = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (lst == NULL)
	{
		current = new_fdlist(fd);
		lst = current;
	}
	else
		current = find_or_create(lst, fd);
	if (current == NULL)
		return (NULL);
	if (!get_next_linebreak(current, &temp, &lst, &result))
		return (result);
	temp = get_after_char(current->content, '\n');
	free(current->content);
	current->content = temp;
	if (temp == NULL)
		fd_lstremove(&lst, fd);
	return (result);
}
