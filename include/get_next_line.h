/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbessonn <cbessonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:11:33 by cbessonn          #+#    #+#             */
/*   Updated: 2023/03/06 15:14:59 by cbessonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include "libft.h"
# define BF_SIZE BUFFER_SIZE
# if (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

bool	line_allocate(char **line, int *malloc_size);
void	line_edit(char **line, char *buffer, int *line_size);
bool	line_read(char *buffer, int fd, char **line, int *n);
char	*line_resize(char **line);
bool	buffer_check(char *buffer, int n);
void	buffer_clean(char *buffer, bool line_found);
bool	buffer_read(char *buffer, int fd, int *n);
bool	get_next_line(int fd, char **line);

#endif
