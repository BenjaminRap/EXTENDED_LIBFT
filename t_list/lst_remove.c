/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:34:33 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_remove(t_list *list, t_node *node, void (*free_value)(void *))
{
	int	index;

	index = find_node_index(list, node);
	if (index < 0)
		return ;
	lst_remove_at(list, index, free_value);
}
