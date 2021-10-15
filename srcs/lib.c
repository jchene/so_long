/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:09:44 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:44:44 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Retourne 0 si 'c' est charset, -1 sinon
int	char_diff(const char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (0);
	return (-1);
}

//Retourne 0 si tout les caracteres de 'string' sont charset, -1 sinon
int	charset_diff(const char *charset, char *line)
{
	int		i;

	i = 0;
	while (line[i])
		if (char_diff(charset, line[i++]) == -1)
			return (-1);
	return (0);
}

//Retourne le nombre d'occurences du caractère 'c' dans la chaine 'line'
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

//Retourne 1 si il existe une diffférence entre les deux strings, 0 sinon
int	extdif(const char *ext, char *dot)
{
	int		dotlen;
	int		extlen;
	int		i;

	i = 0;
	dotlen = ft_strlen(dot);
	extlen = ft_strlen((char *)ext);
	if (dotlen != extlen)
		return (1);
	while (i < dotlen)
	{
		if (ext[i] != dot[i])
			return (1);
		i++;
	}
	return (0);
}

//Verifie si le fichier de nom 'filename' possède l'extension 'ext'
int	check_ext(const char *ext, char *filename)
{
	char	*dot;
	int		len;

	len = ft_strlen(filename) - 1;
	while (len >= 0)
	{
		if (filename[len] == '.')
			dot = &filename[len];
		if (extdif(ext, dot))
			return (-1);
		len--;
	}
	return (0);
}
