/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:27:29 by abourkab          #+#    #+#             */
/*   Updated: 2022/11/09 23:06:13 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			len;
	int			nl;

	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	len = read(fd, buff, BUFFER_SIZE);
	while (len >= 0)
	{
		buff[len] = 0;
		tmp[fd] = ft_strjoin(tmp[fd], buff);
		nl = check_newline(tmp[fd]);
		if (nl != -1)
			return (get_current_line(&tmp[fd], nl));
		if (!len && !tmp[fd][0])
			break ;
		if (!len)
			return (get_reminder(&tmp[fd], 0));
		len = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp[fd]);
	tmp[fd] = NULL;
	return (NULL);
}

char	*get_current_line(char **tmp, int nl)
{
	char	*line;

	line = ft_substr(*tmp, 0, nl + 1);
	*tmp = get_reminder(tmp, nl + 1);
	return (line);
}

char	*get_reminder(char **str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(*str + nl);
	reminder = ft_substr(*str, nl, rlen);
	free(*str);
	*str = NULL;
	return (reminder);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
