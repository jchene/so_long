/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:09:44 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 21:53:27 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Return 0 is 'c' is in charset, -1 otherwise
int	char_diff(const char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (0);
	return (-1);
}

//Return 0 if all 'string' characters are in the charset, -1 otherwise
int	charset_diff(const char *charset, char *line)
{
	int		i;

	i = 0;
	while (line[i])
		if (char_diff(charset, line[i++]) == -1)
			return (-1);
	return (0);
}

//Return the number of occurences of 'c' in string 'line'
int	count_occur(const char c, char *line)
{
	int		occur;
	int		len;
	int		i;

	i = 0;
	occur = 0;
	len = ft_strlen(line);
	while (i < len)
		if (line[i++] == c)
			occur++;
	return (occur);
}

//Return 1 if both strings are different, 0 otherwise
int	extdif(const char *ext, char *dot)
{
	int		dotlen;
	int		extlen;
	int		i;

	i = 0;
	dotlen = ft_strlen(dot);
	extlen = ft_strlen((char *)ext);
	if (dotlen != extlen)
		return (-1);
	while (i < dotlen)
	{
		if (ext[i] != dot[i])
			return (-1);
		i++;
	}
	return (0);
}

//Check if file 'filename' has extension 'ext'
int	check_ext(const char *ext, char *filename)
{
	char	*dot;
	int		len;

	len = ft_strlen(filename) - 1;
	while (len >= 0)
	{
		if (filename[len] == '.')
		{
			dot = &filename[len];
			if (extdif(ext, dot))
				return (-1);
			else
				return (0);
		}
		len--;
	}
	return (-1);
}
