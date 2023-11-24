/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo- <irabelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:07:46 by irabelo-          #+#    #+#             */
/*   Updated: 2023/11/24 18:23:38 by irabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_fd(int fd, char *buffer, char *stash)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*obtain_next_line(char *line)
{
	size_t	i;
	char	*stash;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (NULL);
	stash = ft_substr(line, (i + 1), (ft_strlen(line) - i));
	if (!*stash)
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_from_fd(fd, buffer, stash);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = obtain_next_line(line);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text1.txt", O_RDONLY);
	//fd = open("text2.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		//printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/