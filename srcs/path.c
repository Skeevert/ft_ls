/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:54:29 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/12 15:24:12 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_recursion(t_entlist *new, char *path)
{
	char	path_new[PATH_MAX];

	ft_strcpy(path_new, path);
	if (ft_strcmp(new->ent_name, ".") && ft_strcmp(new->ent_name, "..") &&
			(new->ent_name[0] != '.' || g_options & 0x04))
	{
		if (ft_strlen(path_new) + ft_strlen(new->ent_name) + 1 < PATH_MAX)
		{
			ft_strcat(path_new, "/");
			ft_strcat(path_new, new->ent_name);
			path_init(path_new);
		}
	}
}

void	entity_fill(t_entlist *entity, t_dirent *entry)
{
	t_stat		stat;

	lstat(entry->d_name, &stat);
	strcpy(entity->ent_name, entry->d_name);
	entity->ent_mode = stat.st_mode;
	entity->time = stat.st_mtime;
	entity->link_num = stat.st_nlink;
	entity->uid = stat.st_uid;
	entity->gid = stat.st_gid;
	entity->size = stat.st_size;
}

void	entity_print(t_entlist *list, char *path)
{
	path = 0;

	while (list)
	{
		if (list->ent_name[0] != '.' || g_options & 0x04)
			g_options & 0x01 ? list_init(list) : 0;
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
	}
	merge_sort(&list);
	entity_print(list, path); /* TODO: ADD FLAG MANAGEMENT */
	temp = list;
	while (temp)
	{
		if (temp->ent_mode & S_IFDIR && g_options & 0x02)
			ft_recursion(temp, path);
		temp = temp->next;
	}
	entity_free(list);
	closedir(folder);
}
