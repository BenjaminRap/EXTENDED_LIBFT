/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:44:42 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:09:45 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*add_node(t_list **list, void *value)
{
	t_node	*node;

	if (list == NULL)
		return (NULL);
	if (*list == NULL)
	{
		*list = create_list();
		if (*list == NULL)
			return (NULL);
	}
	node = create_node(value);
	if (node == NULL)
		return (NULL);
	node->next = (*list)->node;
	(*list)->length += 1;
	(*list)->node = node;
	lst_get_last(*list)->next = node;
	return (node);
}
