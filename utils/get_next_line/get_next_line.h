/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:14:47 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 19:57:57 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int				ft_strlen(char *str);
char			*ft_strchr(char *str, char c);
void			ft_bzero(void *b, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlen_nl(char *s);
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*ft_strdup_gnl(char *s);
int				get_next_line(int fd, char **line);
#endif