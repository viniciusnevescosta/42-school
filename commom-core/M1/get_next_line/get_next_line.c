/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:50:14 by vneves-c          #+#    #+#             */
/*   Updated: 2026/08/17 23:32:11 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_line_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*ft_extract_line(char *s)
{
	char	*heap;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_line_len(s);
	heap = malloc(len + 1);
	if (!heap)
		return (NULL);
	i = 0;
	while (i < len)
	{
		heap[i] = s[i];
		i++;
	}
	heap[i] = '\0';
	return (heap);
}

static char	*ft_save_rest(char *s)
{
	size_t	len;
	char	*heap;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_line_len(s);
	if (s[len] == '\0')
		return (NULL);
	heap = malloc((ft_strlen(s) - len) + 1);
	if (!heap)
		return (NULL);
	i = 0;
	while (s[len + i])
	{
		heap[i] = s[len + i];
		i++;
	}
	heap[i] = '\0';
	return (heap);
}

static char	*ft_read_until_new_line(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*tmp;

	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_until_new_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	tmp = stash;
	stash = ft_save_rest(tmp);
	free(tmp);
	return (line);
}
