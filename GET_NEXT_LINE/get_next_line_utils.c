/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:36:01 by marvin            #+#    #+#             */
/*   Updated: 2024/01/19 17:27:11 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdlist	*new_fdlist(int fd)
{
	t_fdlist	*new;

	new = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->content = NULL;
	return (new);
}

t_fdlist	*find_or_create(t_fdlist *lst, int fd)
{
	t_fdlist	*new;

	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	new = new_fdlist(fd);
	lst->next = new;
	return (new);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (str + i);
	return (NULL);
}

char	*ft_strnjoin(char *s1, char *s2, size_t s2_len)
{
	size_t	s1_len;
	char	*result;
	size_t	i;

	i = 0;
	s1_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	result = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		result[i] = s2[i - s1_len];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	fd_lstremove(t_fdlist **lst, int fd)
{
	t_fdlist	*current;
	t_fdlist	*temp;

	current = *lst;
	if ((*lst)->fd == fd)
	{
		*lst = (*lst)->next;
		free(current);
		return ;
	}
	while (current->next != NULL && current->next->fd != fd)
		current = current->next;
	if (current->next == NULL)
		return ;
	temp = current->next;
	current->next = current->next->next;
	free(temp);
}
