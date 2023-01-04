/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:09:03 by fvon-nag          #+#    #+#             */
/*   Updated: 2022/12/14 16:12:55 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ps;
	unsigned char	*pd;

	ps = (unsigned char *) src;
	pd = dest;
	while (n--)
	{
		*pd++ = (unsigned char) *ps++;
	}
	return (dest);
}
