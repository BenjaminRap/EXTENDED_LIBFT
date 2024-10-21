/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:14 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:09:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_node_index(t_list *lst, t_node *node)
{
	int		index;
	t_node	*current;

	index = 0;
	if (lst == NULL)
		return (-1);
	current = lst->node;
	while (index < lst->length)
	{
		if (current == node)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}
