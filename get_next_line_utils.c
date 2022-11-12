/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizgunan <sizgunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:13:18 by sizgunan          #+#    #+#             */
/*   Updated: 2022/11/12 18:50:10 by sizgunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char		*p;
	size_t		i;

	i = 0;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
	{
		free (s);
		return (NULL);
	}
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[len] = '\0';
	free (s);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(len * sizeof(char));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (i < len && s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}
