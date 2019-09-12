/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:53:30 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/12 15:17:06 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <limits.h>
# include <pwd.h>

/*
 * g_options cheatsheet:
 * 0x01: -l
 * 0x02: -R
 * 0x04: -a
 * 0x08: -r
 * 0x10: -t
 */

char						g_options;

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct 			s_entlist
{
	char				ent_name[256];
	mode_t				ent_mode;
	time_t				time;
	nlink_t				link_num;
	uid_t				uid;
	gid_t				gid;
	off_t				size;
	struct s_entlist	*next;
}						t_entlist;

void					path_init(char *path);

t_entlist				*entity_new();
void					entity_add(t_entlist **start, t_entlist *new);
void					entity_free(t_entlist *start);
void					merge_sort(t_entlist **head_ref);
void					list_init(t_entlist *ent);

#endif
