/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:11:15 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/12 15:36:43 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	print(char *str, size_t min_width, char mode)
{
	size_t			len;
	static char		buff[4096];
	static char		*buff_ptr = buff;

	if (mode)
	{
		write(1, buff, ft_strlen(buff));
		buff_ptr = buff;
	}
	else
	{
		len = ft_strlen(str);
		if (buff_ptr + (len > min_width ? len : min_width) > buff + 4095)
		{
			write(1, buff, 4096);
			buff_ptr = buff;
		}
		if (min_width > len)
		{	
			ft_memset(buff_ptr, ' ', min_width - len);
			buff_ptr += (min_width - len);
		}
		ft_strcat(buff_ptr, str);
		buff_ptr += len;
	}
}

/*
char	gruid_to_str(char *u_str, char *g_str, t_entlist *ent)
{
	char	return_val;

	return_val = 0;
	if (!(u_str = getpwuid(ent->uid)))
		return_val |= 0x01;
	if (!(g_str = getgrgid(ent->gid)))
		return_val |= 0x02;
}
*/

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
	char	mode[11];
	
	mode_to_str(mode, ent);	
	printf("%s", mode);
}
