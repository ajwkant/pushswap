/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 13:47:57 by akant         #+#    #+#                 */
/*   Updated: 2021/05/17 11:57:18 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		read_line(char *buffer, int fd);
int		buf_to_line(char **line, char *buffer);
int		ft_strlengnl(char *str, char delim);
int		ft_strccpy(char *s1, char *s2, char c);
void	move_buf_forward(char *buf);
char	*new_str(char *s1, char *s2);

#endif
