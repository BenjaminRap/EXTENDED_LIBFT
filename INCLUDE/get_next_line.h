/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:11:52 by marvin            #+#    #+#             */
/*   Updated: 2024/01/19 20:14:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_fdlist
{
	struct s_fdlist	*next;
	char			*content;
	int				fd;
}	t_fdlist;

t_fdlist	*new_fdlist(int fd);
t_fdlist	*find_or_create(t_fdlist *lst, int fd);
char		*ft_strchr(char *str, char c);
char		*ft_strnjoin(char *s1, char *s2, size_t s2_len);
void		fd_lstremove(t_fdlist **lst, int fd);
char		*get_next_line(int fd);

#endif // !GET_NEXT_LINE_H
