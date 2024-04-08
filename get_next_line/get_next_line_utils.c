/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:54:02 by yawang            #+#    #+#             */
/*   Updated: 2024/04/08 18:50:37 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Look for a new line character in the given linked list */

int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;
	
	if (stash == NULL)
		return (0);
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* Return a pointer to the last node in the stash */

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;
	
	current = stash;
	while (current && current->next)
		current = current->next;
	return(current);
}