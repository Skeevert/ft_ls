/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:32:53 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/20 13:35:52 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	buff_management(char *str, char mode)
{
	static char buff[BUFF_SIZE];
	static char *buff_ptr = buff;

	if (!mode)
	{
		while (*str)
		{
			if (buff_ptr - buff >= BUFF_SIZE - 1)
			{
				write(1, buff, strlen(buff));
				buff_ptr = buff;
				memset(buff_ptr, 0, BUFF_SIZE);
			}
			*buff_ptr = *str;
			str++;
			buff_ptr++;
		}
	}
	else
	{
		write(1, buff, strlen(buff));
		buff_ptr = buff;
		memset(buff_ptr, 0, BUFF_SIZE);
	}
}
