/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:57:02 by fvon-nag          #+#    #+#             */
/*   Updated: 2022/12/20 15:20:17 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
	i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*out;

	if ((nmemb >= __SIZE_MAX__ && size >= __SIZE_MAX__))
		return (NULL);
	out = (unsigned char *) malloc(nmemb * size);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		out[i] = 0;
		i++;
	}
	return (out);
}

static char	*transfer(char const *s1, char *out, int startpoint, int endpoint)
{
	int	i;
	int	j;

	i = startpoint;
	j = 0;
	while (i < endpoint)
	{
		out[j] = s1[i];
		j++;
		i++;
	}
	return (out);
}

static int	strnstrindex(const char	*haystack, const char *needle)
{
	size_t		i;
	size_t		c;

	i = 0;
	while (haystack[i] != '\0')
	{
		c = 0;
		while (haystack[i + c] != '\0' && haystack[i + c] == needle[c])
		{
			if (needle[c + 1] == '\0')
				return ((int)i);
			c++;
		}
		i++;
	}
	return (0);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		setlength;
	int		startpoint;
	int		endpoint;

	setlength = ft_strlen(set);
	startpoint = strnstrindex(s1, set) + setlength;
	if (strnstrindex(s1 + startpoint, set) == 0)
		endpoint = ft_strlen(s1) - 1;
	else
		endpoint = strnstrindex(s1 + startpoint, set) + startpoint;

	out = (char *)ft_calloc((ft_strlen(s1) + 1) - (endpoint - startpoint),
			sizeof(char));
	return (transfer(s1, out, startpoint, endpoint));
}

int main(void)
{
	ft_strtrim("abc aaeraeraer abc", "abc");
}
