/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:39:09 by jchene            #+#    #+#             */
/*   Updated: 2021/09/12 21:44:09 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *string);
void	ft_strcpyn(char *dst, char *src);
void	ft_strcatn(char *dst, char *src);
void	*ft_memset(void *s, int c, int n);
void	*ft_calloc(int count, int size);
#endif
