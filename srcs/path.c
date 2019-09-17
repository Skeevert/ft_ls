/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:54:29 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/17 17:29:33 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*path_add(char *path, char *name)
{
	ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}

void	ft_recursion(t_entlist *new, char *path)
{
	char	path_new[PATH_MAX];

	ft_strcpy(path_new, path);
	if (ft_strcmp(new->ent_name, ".") && ft_strcmp(new->ent_name, "..") &&
			(new->ent_name[0] != '.' || g_options & 0x04))
	{
		if (ft_strlen(path_new) + ft_strlen(new->ent_name) + 1 < PATH_MAX)
		{
			path_add(path_new, new->ent_name);
			path_init(path_new);
		}
	}
}

void	entity_fill(t_entlist *entity, t_dirent *entry, char *path)
{
	t_stat		stat;
	size_t		len;
	char 		*temp;
	char		path_new[PATH_MAX];

	ft_strcpy(path_new, path);
	lstat(path_add(path_new, entry->d_name), &stat);
	strcpy(entity->ent_name, entry->d_name);
	entity->ent_mode = stat.st_mode;
	entity->time = stat.st_mtime;
	entity->link_num = stat.st_nlink;
	entity->uid = stat.st_uid;
	entity->gid = stat.st_gid;
	entity->size = stat.st_size;
	temp = ft_itoa(entity->link_num);
	len = ft_strlen(temp);
	len > g_maxlinks ? g_maxlinks = len : 0;
	free(temp);
	len = ft_strlen(uid_to_name(entity));
	len > g_maxuid ? g_maxuid = len : 0;
	len = ft_strlen(gid_to_name(entity));
	len > g_maxgid ? g_maxgid = len : 0;
	temp = ft_itoa(entity->size);
	len = ft_strlen(temp);
	len > g_maxsize ? g_maxsize = len : 0;
	free(temp);
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
		entity_fill(temp, entry, path);
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
