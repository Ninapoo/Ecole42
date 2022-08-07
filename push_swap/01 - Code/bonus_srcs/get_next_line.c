/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:11:44 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 14:41:42 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	static char	*temp_line;
	char		*line;
	int			buffer_size;

	buffer_size = 1;
	if (fd < 0 || buffer_size <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!temp_line)
	{
		temp_line = (char *)malloc(1 * sizeof(char));
		temp_line[0] = 0;
	}
	temp_line = ft_temp_line(fd, temp_line);
	if (!temp_line)
		return (NULL);
	line = ft_make_line(temp_line);
	temp_line = ft_new_temp_line(temp_line);
	if (temp_line == NULL)
		free (temp_line);
	return (line);
}

/*
 read the line until \n is found, save each buffer_sized piece
 of line into temp_line
 */
char	*ft_temp_line(int fd, char *temp_line)
{
	char	*buff;
	int		read_ret;
	int		buffer_size;

	buffer_size = 10;
	buff = malloc((buffer_size + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_ret = 1;
	while (!ft_find_nl(temp_line) && read_ret != 0)
	{
		read_ret = read(fd, buff, buffer_size);
		if (read_ret == -1)
		{
			free(temp_line);
			free(buff);
			return (NULL);
		}
		buff[read_ret] = '\0';
		temp_line = ft_strjoin(temp_line, buff);
	}
	free(buff);
	return (temp_line);
}

/*
 Looks for next line in a string. 
 Returns 1 if next line is found so that the ft_temp_line stops reading
 and returns the temp_line. 
 Returns 0 if next line is not found. 
 */
int	ft_find_nl(char *temp_line)
{
	int	i;

	i = 0;
	while (temp_line[i])
	{
		if (temp_line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//  Make the \n terminated line from the temp_line
char	*ft_make_line(char *temp_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!temp_line[i])
		return (NULL);
	while (temp_line[i] && temp_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		temp_line = NULL;
	i = 0;
	while (temp_line[i] && temp_line[i] != '\n')
	{
		str[i] = temp_line[i];
		i++;
	}
	if (temp_line[i] == '\n')
	{
		str[i] = temp_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
Once the next line has been returned, create the new temp_line by
removing the previous next_line from it.
 */
char	*ft_new_temp_line(char *temp_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (temp_line[i] && temp_line[i] != '\n')
		i++;
	if (!temp_line[i])
	{
		free(temp_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(temp_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (temp_line[i])
		str[j++] = temp_line[i++];
	str[j] = '\0';
	free(temp_line);
	return (str);
}
