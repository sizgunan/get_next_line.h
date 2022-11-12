/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizgunan <sizgunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:52:20 by sizgunan          #+#    #+#             */
/*   Updated: 2022/11/12 08:35:25 by sizgunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*save_the_rest(char	*buffer_return);
char	*get_me_line(char *buffer_return);
char	*get_next_line(int fd);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_join_and_check(int fd, char *buffer_return);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);

#endif
