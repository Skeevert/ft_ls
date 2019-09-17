/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:11:15 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/17 16:23:30 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*uid_to_name(t_entlist *ent)
{
	struct passwd	*pw_ptr;
	static char		numstr[10];
	char			*num;

	if (!(pw_ptr = getpwuid(ent->uid)))
	{
		bzero(numstr, 10);
		num = ft_itoa(ent->uid);
		strncpy(numstr, num, 9);
		free(num);
		return (numstr);
	}
	else
		return pw_ptr->pw_name;
}

char	*gid_to_name(t_entlist *ent)
{
	struct group	*grp_ptr;
	static char		numstr[10];
	char			*num;

	if (!(grp_ptr = getgrgid(ent->gid)))
	{
		bzero(numstr, 10);
		num = ft_itoa(ent->gid);
		strncpy(numstr, num, 9);
		free(num);
		return (numstr);
	}
	else
		return grp_ptr->gr_name;

}

void	mode_to_str(char *str, t_entlist *ent)
{
	ft_strcpy(str, "----------");
	S_ISDIR(ent->ent_mode) ? str[0] = 'd' : 0;
	S_ISCHR(ent->ent_mode) ? str[0] = 'c' : 0;
	S_ISBLK(ent->ent_mode) ? str[0] = 'b' : 0;
	S_ISLNK(ent->ent_mode) ? str[0] = 'l' : 0;
	ent->ent_mode & S_IRUSR ? str[1] = 'r' : 0;
	ent->ent_mode & S_IWUSR ? str[2] = 'w' : 0;
	ent->ent_mode & S_IXUSR ? str[3] = 'x' : 0;
	ent->ent_mode & S_IRGRP ? str[4] = 'r' : 0;
	ent->ent_mode & S_IWGRP ? str[5] = 'w' : 0;
	ent->ent_mode & S_IXGRP ? str[6] = 'x' : 0;
	ent->ent_mode & S_IROTH ? str[7] = 'r' : 0;
	ent->ent_mode & S_IWOTH ? str[8] = 'w' : 0;
	ent->ent_mode & S_IXOTH ? str[9] = 'x' : 0;
	str[10] = 0;
}

void	list_init(t_entlist *ent)
{
	char	mode[10000];
	char	*temp;
	
	mode_to_str(mode, ent);	
	temp = ft_itoa(ent->link_num);
	ft_stroffcat(mode, temp, g_maxlinks + 1, 0);
	free(temp);
	ft_strcat(mode, " ");
	ft_stroffcat(mode, uid_to_name(ent), g_maxuid + 1, 1);
	ft_strcat(mode, " ");
	ft_stroffcat(mode, gid_to_name(ent), g_maxgid + 1, 1);
	ft_strcat(mode, " ");
	temp = ft_itoa(ent->size);
	ft_stroffcat(mode, temp, g_maxsize, 0);
	free(temp);
	ft_strcat(mode, " ");
	ft_stroffcat(mode, 4 + ctime(&ent->time), 12, 0);
	ft_strcat(mode, " ");
	ft_strcat(mode, ent->ent_name);
	ft_strcat(mode, "\n");
	ft_putstr(mode);
}
