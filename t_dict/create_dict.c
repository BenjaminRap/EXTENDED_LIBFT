/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:26:53 by brappo            #+#    #+#             */
/*   Updated: 2024/01/19 20:15:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dict	*create_dict(void)
{
	t_dict	*dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	if (dict == NULL)
		return (NULL);
	dict->length = 0;
	dict->keys = NULL;
	dict->values = NULL;
	return (dict);
}
