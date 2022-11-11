/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizgunan <sizgunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:29:48 by sizgunan          #+#    #+#             */
/*   Updated: 2022/11/11 17:19:06 by sizgunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_the_rest(char	*buffer_return)
{
	char	*save;
	size_t	nl_index;
	size_t	end;

	nl_index = 0;
	end = 0;
	while (buffer_return[nl_index] && buffer_return[nl_index] != '\n')
		nl_index++;
	nl_index++;
	end = ft_strlen(buffer_return) - nl_index;
	save = ft_substr(buffer_return, nl_index, end + 1);
	if (!save)
	{
		free(buffer_return);
		return (NULL);
	}
	free(buffer_return);
	return (save);
}

char	*get_me_line(char *buffer_return)
{
	char		*line;
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
	len++;
	i = 0;
	while (i < len)
	{
		line[i] = buffer_return[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_join_and_check(int fd, char *buffer_return)
{
	char	*buffer;
	int		rd;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd >= 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (rd == 0 || (rd == 0 && *buffer_return))
			break ;
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
// 		printf("error fd");
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
