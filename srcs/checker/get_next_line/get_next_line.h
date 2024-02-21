/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:23:50 by dabae             #+#    #+#             */
/*   Updated: 2024/02/21 17:04:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_link_list
{
	char				*str_tmp;
	struct s_link_list	*next;
}			t_link_list;

char		*get_next_line(int fd);

int			found_n(t_link_list *buf_list);

int			ft_strlen_gnl(char *s);

void		free_list(t_link_list *buf_list);

void		prep_line(char **line, t_link_list *buf_list);

t_link_list	*ft_lastnode(t_link_list *buf_list);

#endif
