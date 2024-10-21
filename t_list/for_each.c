/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:13:38 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:09:56 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	for_each(t_list *list, void (*f)(void *))
{
	int		index;
	t_node	*current;

	index = 0;
	if (list == NULL)
		return ;
	current = list->node;
	while (index < list->length)
	{
		f(current->value);
		current = current->next;
		index++;
	}
}
