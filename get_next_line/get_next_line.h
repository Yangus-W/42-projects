/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:53:43 by yawang            #+#    #+#             */
/*   Updated: 2024/04/08 18:40:57 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>


/* In case the buffer size is not defined during compilation */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		found_newline(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	read_and_stash(int fd, t_list **stash, int *readed_ptr);
void	add_to_stash(t_list **stash, char *buffer, int readed);
void	extract_line(t_list *stash, char **line);
void	generate_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
void	ft_strlen(char *str);
void	free_stash(t_list *stash);

#endif