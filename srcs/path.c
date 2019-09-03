#include "main.h"

void	print_list(t_list *list)
{
	t_dirent	*to_print;
	while (list)
	{
		to_print = (t_dirent *)list->content;
		ft_putstr("kek\n");

		ft_putstr(to_print->d_name);
		list->next ? write(1, " ", 1) : 0;
		list = list->next;
	}
}

void	free_list(t_list *list)
{
	t_list *temp;
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	path_init(char *path)
{
	DIR		*folder;
	t_dirent	*entry;
	t_list		*list;
	t_list		*current;

	folder = opendir(path);
	if (!folder)
		return ; /* TODO: ADD ERROR MANAGEMENT */
	while ((entry = readdir(folder))) /* Not sure if this works */
	{
		if (!list)
		{
			if (!(list = ft_lstnew(entry, sizeof(entry))))
				return ;
		}	
		else
		{
			if (!(current = ft_lstnew(entry, sizeof(entry))))
				return ;
			ft_lstadd(&list, current);
		}
	}
	ft_putstr("kek\n");
	print_list(current);
	free_list(current);
	closedir(folder);
}
