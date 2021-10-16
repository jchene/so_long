/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:14:21 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 20:26:39 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen_nl(s2) + 1));
	if (cpy == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		cpy[i] = s2[j];
		i++;
		j++;
	}
	cpy[i] = '\0';
	free(s1);
	return (cpy);
}

char	*ft_strdup_gnl(char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen_nl(s) + 1));
	if (cpy == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	get_next_line(int fd, char **line)
{
	static int	ret;
	static char	buffer[1 + 1];

	*line = ft_strdup_gnl(buffer);
	if (fd < 0 || !line || read(fd, buffer, 0) == -1 || 1 <= 0)
		return (-1);
	if (ft_strchr(buffer, '\n') == 0)
	{
		while (read(fd, buffer, 1) > 0)
		{
			buffer[1] = '\0';
			*line = ft_strjoin_gnl(*line, buffer);
			if (ft_strchr(buffer, '\n') != 0)
				break ;
		}
	}
	if (ret < 1 && ft_strchr(buffer, '\n') == 0)
	{
		ft_bzero(buffer, 1 + 1);
		return (0);
	}
	ft_memmove(buffer, buffer + ft_strlen_nl(buffer) + 1,
		ft_strlen(buffer) - ft_strlen_nl(buffer));
	return (1);
}
