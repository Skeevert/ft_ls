/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:34:28 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/18 13:32:50 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*path_add(char *path, char *name)
{
	ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}

void	print_total(t_entlist *ent)
{
	char		*temp;
	char		output[30];
	blkcnt_t	total;

	total = 0;
	while (ent)
	{
		total += ent->blocks;
		ent = ent->next;
	}
	temp = ft_itoa(total);
	if (!temp)
		return ;
	ft_strcpy(output, "total ");
	ft_strcat(output, temp);
	ft_strcat(output, "\n");
	free(temp);
	ft_putstr(output);
}

char	*print_link(t_entlist *ent, char *path)
{
	char		path_new[PATH_MAX];
	static char	output[261];

	ft_bzero(output, 261);
	ft_strcpy(path_new, path);
	path_add(path_new, ent->ent_name);
	ft_strcpy(output, " -> ");
	readlink(path_new, output + 4, 256);
	return (output);
}	