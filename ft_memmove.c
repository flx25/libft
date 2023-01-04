/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:14:48 by fvon-nag          #+#    #+#             */
/*   Updated: 2022/12/20 11:28:40 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*csrc;
	char	*cdest;

	csrc = (char *) src;
	cdest = (char *) dest;
	i = 0;
	if (src + n >= dest)
	{
		i = n - 1;
		while (i >= 0)
		{
			cdest[i] = csrc[i];
			i--;
		}
	}
	else
	{
		while (i < (int) n)
		{
		cdest[i] = csrc[i];
		i++;
		}
	}
	return (dest);
}
