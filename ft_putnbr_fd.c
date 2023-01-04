/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:48:40 by fvon-nag          #+#    #+#             */
/*   Updated: 2022/12/20 15:34:48 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <limits.h>

static int	countlength(int n)
{
	int	length;

	length = 1;
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	transfer(char *out, int n, int isminus, int *isintmin)
{
	int	i;
	int	length;

	if (n == INT_MIN)
	{
		n = INT_MAX;
		*isintmin = 1;
	}
	length = countlength(n);
	i = length - 2 + isminus;
	while (i >= 0)
	{
		out[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

static void	extracases(int isminus, int iszero, int isintmin, char *out)
{
	if (isminus == 1)
		out[0] = '-';
	if (iszero == 1)
		out[0] = '0';
	if (isintmin == 1)
		out[10] = '8';
}

static int	isminus_f(int n, int *isminus)
{
	if (n < 0)
	{
		*isminus = 1;
		n *= -1;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		length;
	char	out[12];
	int		isminus;
	int		iszero;
	int		isintmin;

	iszero = 0;
	while (iszero <= 12)
	{
		out[iszero] = '\0';
		iszero++;
	}
	iszero = 0;
	isminus = 0;
	isintmin = 0;
	n = isminus_f(n, &isminus);
	if (n == 0)
		iszero = 1;
	length = countlength(n);
	transfer(out, n, isminus, &isintmin);
	extracases(isminus, iszero, isintmin, out);
	write(fd, out, length);
}
