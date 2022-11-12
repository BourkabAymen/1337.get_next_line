/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:26:21 by abourkab          #+#    #+#             */
/*   Updated: 2022/11/10 19:14:02 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// This function return a string from the start 
//of the file having fd as its file descriptor till the first occurance of \n
char	*get_next_line(int fd)
{
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];
	int			len;
	int			nl;

	if (!tmp)
		tmp = ft_strdup("");
	len = read(fd, buff, BUFFER_SIZE);
	while (len >= 0)
	{
		buff[len] = 0;
		tmp = ft_strjoin(tmp, buff);
		nl = check_newline(tmp);
		if (nl != -1)
			return (get_current_line(&tmp, nl));
		if (!len && !tmp[0])
			break ;
		if (!len)
			return (get_rest(&tmp, 0));
		len = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp);
	tmp = NULL;
	return (NULL);
}

// This function return a substring from *tmp 
// and modify *tmp
char	*get_current_line(char **tmp, int nl)
{
	char	*line;

	line = ft_substr(*tmp, 0, nl + 1);
	*tmp = get_rest(tmp, nl + 1);
	return (line);
}

// this function return the string from the last \n
// in ordre to modify *tmp
char	*get_rest(char **str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(*str + nl);
	reminder = ft_substr(*str, nl, rlen);
	free(*str);
	*str = NULL;
	return (reminder);
}

// This function check the occurance of a \n and return its index
int	check_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// This function return the length of s
size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
