/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:58:10 by fvon-nag          #+#    #+#             */
/*   Updated: 2022/12/21 14:42:48 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*lastcurrent;

	if (lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		del(current->content);
		if (current->next != NULL)
		{
			lastcurrent = current;
			current = current->next;
			del(lastcurrent);
		}
		else
		{
			del(current);
			*lst = NULL;
			return ;
		}
	}
}
