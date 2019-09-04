/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:54:29 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/04 15:56:55 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	entity_print(t_entlist *list)
{
	while (list)
	{
		if (list->ent_name[0] != '.' || g_options & 0x04)
		{
			ft_putstr(list->ent_name);
			list->next ? write(1, "\n", 1) : 0; /* Separator variable could be used to implement -l option */
		}
		list = list->next;
	}
}

void	path_init(char *path)
{
	DIR			*folder;
	t_dirent	*entry;
	t_entlist	*list;
	t_entlist	*temp;

	folder = opendir(path);
	if (!folder)
		return ; /* TODO: ADD ERROR MANAGEMENT */
	list = 0;
	while ((entry = readdir(folder))) /* Not sure if this works */
	{
		temp = entity_new();
		ft_strcpy(temp->ent_name, entry->d_name); /*Could be done with separate function */
		entity_add(&list, temp);
	}
	entity_print(list); /* TODO: ADD FLAG MANAGEMENT */
	entity_free(list);
	closedir(folder);
}
