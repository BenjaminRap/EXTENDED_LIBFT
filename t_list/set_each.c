/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_each.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:19:58 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_each(t_list *list, void *(*f)(void *))
{
	int		index;
	t_node	*current;

	index = 0;
	current = list->node;
	while (index < list->length)
	{
		current->value = f(current->value);
		current = current->next;
		index++;
	}
}
