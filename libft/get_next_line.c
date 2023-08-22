/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:42:16 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/09 11:01:58 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Keep the info that is after '\n' for the following next_get_line.

static char	*ft_keep_for_next(char *buf_line)
{
	char			*temp4;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (buf_line[i] != '\0' && buf_line[i] != '\n')
		i++;
	if (!buf_line[i])
	{
		free(buf_line);
		return (NULL);
	}
	temp4 = malloc(ft_strlen_gnl(buf_line) - i + 1 * sizeof(char));
	if (!temp4)
		return (NULL);
	i++;
	j = 0;
	while (buf_line[i] != '\0')
		temp4[j++] = buf_line[i++];
	temp4[j] = '\0';
	free(buf_line);
	return (temp4);
}

// Debug line and return depending if it is end of line or end of file.
// it's important +2 due to /n and /0.

static char	*ft_debug_line(char *buf_line)
{
	char			*temp3;
	unsigned int	i;

	if (!buf_line || !*buf_line)
		return (NULL);
	i = 0;
	while (buf_line[i] != '\0' && buf_line[i] != '\n')
		i++;
	temp3 = malloc(i + 2 * sizeof(char));
	if (!temp3)
		return (NULL);
	i = 0;
	while (buf_line[i] != '\0' && buf_line[i] != '\n')
	{
		temp3[i] = buf_line[i];
		i++;
	}
	if (buf_line[i] == '\n')
		temp3[i++] = '\n';
	temp3[i] = '\0';
	return (temp3);
}

// Join characters from buf_line and temp1.

static char	*ft_making_line(char *buf_line, char *temp1)
{
	char			*temp2;
	size_t			t_len;
	unsigned int	i;
	unsigned int	j;

	t_len = (ft_strlen_gnl(buf_line) + ft_strlen_gnl(temp1));
	temp2 = malloc(t_len + 1 * sizeof(char));
	if (!buf_line || !temp1 || !temp2)
		return (NULL);
	i = 0;
	while (buf_line[i] != '\0')
	{
		temp2[i] = buf_line[i];
		i++;
	}
	j = 0;
	while (temp1[j] != '\0')
		temp2[i++] = temp1[j++];
	temp2[t_len] = '\0';
	free(buf_line);
	return (temp2);
}

// Read based on the BUFFER_SIZE and making a line until a '\n' if found.

static char	*ft_read_file(int fd, char *buf_line)
{
	char		*temp1;
	ssize_t		bytes_read;

	temp1 = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp1)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(buf_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp1, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp1);
			return (NULL);
		}
		temp1[bytes_read] = '\0';
		buf_line = ft_making_line(buf_line, temp1);
	}
	free(temp1);
	return (buf_line);
}

// First errors control, it's important to free buf_line if there is an error,
// debug read_error.txt test.

char	*get_next_line(int fd)
{
	static char		*buf_line[1024];
	char			*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE < 1 || read(fd, 0, 0))
	{
		free(buf_line[fd]);
		buf_line[fd] = NULL;
		return (NULL);
	}
	if (!buf_line[fd])
	{
		buf_line[fd] = malloc(1 * sizeof(char));
		if (!buf_line[fd])
			return (NULL);
		*buf_line[fd] = '\0';
	}
	buf_line[fd] = ft_read_file(fd, buf_line[fd]);
	line = ft_debug_line(buf_line[fd]);
	buf_line[fd] = ft_keep_for_next(buf_line[fd]);
	return (line);
}
