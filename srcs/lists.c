/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:33:01 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/20 13:37:52 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_entlist		*entity_new(void)
{
	t_entlist	*new;

	if (!(new = (t_entlist *)malloc(sizeof(t_entlist))))
	{
		perror("malloc");
		return (0);
	}
	ft_bzero(new, sizeof(t_entlist));
	return (new);
}

void			entity_add(t_entlist **start, t_entlist *new)
{
	if (!start || !new)
		return ;
	if (!(*start))
	{
		*start = new;
		return ;
	}
	new->next = *start;
	*start = new;
}

void			entity_free(t_entlist *start)
{
	t_entlist	*temp;

	while (start)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
}
