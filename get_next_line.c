/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizgunan <sizgunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:29:48 by sizgunan          #+#    #+#             */
/*   Updated: 2022/11/12 18:55:19 by sizgunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_the_rest(char	*buffer_return)
{
	char	*save;
	size_t	nl_index;
	size_t	length;

	nl_index = 0;
	length = 0;
	if (!buffer_return[nl_index])
	{
		free(buffer_return);
		return (NULL);
	}
	while (buffer_return[nl_index] && buffer_return[nl_index] != '\n')
		nl_index++;
	nl_index++;
	length = ft_strlen(buffer_return) - nl_index;
	save = ft_substr(buffer_return, nl_index, length + 1);
	// free(buffer_return);
	// if (!save)
	// {
	// 	free (save);
	// 	return (NULL);
	// }
	return (save);
}

char	*get_me_line(char *buffer_return)
{
	char		*line;
	size_t		len;
	size_t		i;

	len = 0;
	if (!(buffer_return[len]))
		return (NULL);
	while (buffer_return[len] && buffer_return[len] != '\n')
		len++;
	len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (free(buffer_return), NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer_return[i];
		i++;
	}
	return (line[i] = '\0', line);
}

char	*ft_join_and_check(int fd, char *buffer_return)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (rd >= 0)
	{
		if (ft_strchr(buffer_return, '\n'))
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0 || (rd == 0 && *buffer_return))
			break ;
		if (rd < 0)
		{
			free (buffer_return);
			free (buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		buffer_return = ft_strjoin(buffer_return, buffer);
	}
	free(buffer);
	return (buffer_return);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_return = ft_join_and_check(fd, buffer_return);
	if (!buffer_return)
		return (NULL);
	line = get_me_line(buffer_return);
	buffer_return = save_the_rest(buffer_return);
	return (line);
}

// int main(void)
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("error occured");
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close (fd);
// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
