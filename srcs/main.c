/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:55:11 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/10 14:47:06 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_option_save(char *str)
{
	while(*str)
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

void	ft_option_init(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1])
			ft_option_save(argv[i] + 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		path_count;

	g_options = 0;
	path_count = 0;
	i = 1;
	ft_option_init(argc, argv);
	while (i < argc)
	{
		if (argv[i][0] != '-' || !argv[i][1])
		{
			path_init(argv[1]);
			path_count++;
		}
		i++;
	}
	if (path_count == 0)
		path_init(".");
	return (0);
}
