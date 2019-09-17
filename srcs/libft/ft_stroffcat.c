/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroffcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:03:32 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/17 15:25:30 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stroffcat(char *dst, const char *src, size_t num, char mode)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	while (dst[i])
		i++;
	if (mode)
		while (num)
		{
			dst[i] = src[j] ? src[j] : ' ';
			i++;
			src[j] ? j++ : 0;
			num--;
		}
	else
		while (num)
		{
			dst[i] = num > len ? ' ' : src[j];
			num > len ? 0 : j++;
			num--;
			i++;
		}
	dst[i] = 0;
	return (dst);
}
