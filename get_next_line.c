/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizgunan <sizgunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:29:48 by sizgunan          #+#    #+#             */
/*   Updated: 2022/11/09 20:00:39 by sizgunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_me_line(char *buffer_return)
{
	char		*line;
	char		*save;
	size_t		len;
	size_t		i;

	len = 0;
	while (buffer_return[len] && buffer_return[len] != '\n')
		len++;
	if (buffer_return[len] == '\n')
		line = malloc((len + 2) * sizeof(char));
	else
		line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer_return[i];
		i++;
	}
	save = ft_substr(buffer_return, i, ft_strlen(buffer_return) - i);
	buffer_return = save;
	line[i] = '\0';
	return (line);
}

char	*ft_check_and_allocate(int fd, char *buffer_return)
{
	char	*buffer;
	int		rd;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		buffer[rd] = '\0';
		buffer_return = ft_strjoin(buffer_return, buffer);
		if (ft_strchr(buffer_return, '\n'))
			break ;
	}
	free(buffer);
	return (buffer_return);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer_return;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_return = ft_check_and_allocate(fd, &buffer_return);
	if (!buffer_return)
		return (NULL);
	line = get_me_line(buffer_return);
	return (line);
}
