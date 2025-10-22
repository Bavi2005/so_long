/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:51:07 by bpichyal          #+#    #+#             */
/*   Updated: 2025/06/14 14:51:09 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_tukar(int fd, char *bowl, char *bucket, int *byte_read)
{
	char	*temp;

	*byte_read = read(fd, bucket, BUFFER_SIZE);
	if (*byte_read == -1)
	{
		free(bucket);
		free(bowl);
		return (NULL);
	}
	bucket[*byte_read] = '\0';
	temp = bowl;
	temp = ft_strjoin(bowl, bucket);
	if (!temp)
	{
		free(bowl);
		return (NULL);
	}
	free(bowl);
	return (temp);
}

char	*read_file(int fd, char *bowl)
{
	char	*bucket;
	int		byte_read;

	byte_read = 1;
	bucket = malloc(BUFFER_SIZE + 1);
	if (!bucket)
		return (NULL);
	while (!has_fish(bowl) && byte_read > 0)
	{
		bowl = read_tukar(fd, bowl, bucket, &byte_read);
		if (!bowl)
			return (NULL);
	}
	free(bucket);
	return (bowl);
}

char	*extract_line(char *s)
{
	int		i;
	int		j;
	char	*line;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_leftovers(char *s)
{
	int		i;
	int		j;
	char	*left;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	i++;
	left = malloc(ft_strlen(s + i) + 1);
	if (!left)
	{
		free(s);
		return (NULL);
	}
	j = 0;
	while (s[i])
		left[j++] = s[i++];
	left[j] = '\0';
	free(s);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*bowl;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bowl = read_file(fd, bowl);
	if (!bowl)
		return (NULL);
	line = extract_line(bowl);
	if (!line)
	{
		free(bowl);
		bowl = NULL;
		return (NULL);
	}
	bowl = save_leftovers(bowl);
	return (line);
}

/*
gnl?

anywayyyy so for your information in case u didnt get to understand la
static char * bowl is to remember la 
read file tauu la
extract line is to take untill \n
keep leftovers is to put the left over inside the bowl after \n is extracted

read file?
ok what it does is creates bucket of buffer size
search for \n 
returns the leftovers to bowl when \n is found

extract line?
im lasy to write illl explain la

*/
