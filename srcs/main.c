/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:33:07 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/20 13:38:36 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_option_save(char *str)
{
	while (*str)
	{
		if (*str == 'l')
			g_options |= 0x01;
		else if (*str == 'R')
			g_options |= 0x02;
		else if (*str == 'a')
			g_options |= 0x04;
		else if (*str == 'r')
			g_options |= 0x08;
		else if (*str == 't')
			g_options |= 0x10;
		str++;
	}
}

void	max_init(void)
{
	g_maxlinks = 0;
	g_maxuid = 0;
	g_maxgid = 0;
	g_maxsize = 0;
	g_options = 0;
}

void	ft_option_init(int argc, char **argv)
{
	int		i;
	int		path_count;

	i = 1;
	path_count = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] && argv[i][1] != '-')
	{
		ft_option_save(argv[i] + 1);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || !argv[i][1])
			path_count++;
		i++;
	}
	path_count > 1 ? g_options |= 0x20 : 0;
}

int		main(int argc, char **argv)
{
	int		i;
	int		path_count;

	max_init();
	path_count = 0;
	i = 1;
	ft_option_init(argc, argv);
	argv = sort_params(argc, argv);
	while (i < argc)
	{
		if (argv[i][0] != '-' || !argv[i][1])
		{
			path_init(argv[i]);
			path_count++;
			i < argc - 1 ? write(1, "\n", 1) : 0;
		}
		i++;
	}
	if (path_count == 0)
		path_init(".");
	buff_management(0, 1);
	return (0);
}
