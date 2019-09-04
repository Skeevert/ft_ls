/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:54:29 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/04 17:17:47 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	recursion(t_entlist *list)
{
	if (ft_strcmp(list->ent_name, ".") && ft_strcmp(list->ent_name, ".."))
	{
		write(1, "\n", 1);
		ft_putstr(list->ent_name);
		write(1, ":\n", 2);
		path_init(list->ent_name);
	}
}

void	entity_fill(t_entlist *entity, t_dirent *entry)
{
	t_stat		stat;

	lstat(entry->d_name, &stat);
	strcpy(entity->ent_name, entry->d_name);
	entity->ent_mode = stat.st_mode;
}

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
		entity_fill(temp, entry);
		entity_add(&list, temp);
		if (S_ISDIR(list->ent_mode) && g_options & 0x02)
			recursion(list);
	}
	entity_print(list); /* TODO: ADD FLAG MANAGEMENT */
	entity_free(list);
	closedir(folder);
}
