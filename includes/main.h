/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:53:30 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/18 16:41:46 by hshawand         ###   ########.fr       */
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
# include <grp.h>
# include <time.h>
# include <stdio.h>

/*
 * g_options cheatsheet:
 * 0x01: -l
 * 0x02: -R
 * 0x04: -a
 * 0x08: -r
 * 0x10: -t
 */

char					g_options;

nlink_t					g_maxlinks;
size_t					g_maxuid;
size_t					g_maxgid;
size_t					g_maxsize;

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
	blkcnt_t			blocks;
}						t_entlist;

void					path_init(char *path);

t_entlist				*entity_new();
void					entity_add(t_entlist **start, t_entlist *new);
void					entity_free(t_entlist *start);
void					merge_sort(t_entlist **head_ref);
void					list_init(t_entlist *ent, char *path);
char					*uid_to_name(t_entlist *ent);
char					*gid_to_name(t_entlist *ent);
char					*path_add(char *path, char *name);
void					print_total(t_entlist *ent);
char					*print_link(t_entlist *ent, char *path);
void					print_path(char *path);
char					**sort_params(int n, char **arr);
void					simple_print(t_entlist *list);

#endif
