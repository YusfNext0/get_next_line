/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:21:13 by ynachat           #+#    #+#             */
/*   Updated: 2024/02/07 15:31:14 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	test(char **str, int fd)
{
	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) == -1
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (-1);
	*str = (char *)malloc((int)BUFFER_SIZE + 1);
	if (!*str)
		return (-1);
	return (0);
}

char	*fline(char *str)
{
	char	*fstr_stock;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[0])
		return (NULL);
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		j++;
	fstr_stock = malloc(sizeof(char) * j + 1);
	if (!fstr_stock)
		return (NULL);
	while (i < j)
	{
		fstr_stock[i] = str[i];
		i++;
	}
	fstr_stock[i] = '\0';
	return (fstr_stock);
}

char	*sline(char *str)
{
	char	*str_stock;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		j++;
	x = 0;
	while (str[j + x])
		x++;
	str_stock = malloc(sizeof(char) * x + 1);
	if (!str_stock)
		return (free(str), str = NULL, NULL);
	while (i < x)
		str_stock[i++] = str[j++];
	str_stock[i] = '\0';
	free(str);
	str = NULL;
	return (str_stock);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line[OPEN_MAX];
	size_t		i;
	char		*return_str;

	i = 1;
	if (test(&buffer, fd) == -1)
		return (free(line[fd]), line[fd] = NULL, NULL);
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		line[fd] = ft_strjoin(line[fd], buffer);
		if (!line[fd] || check(line[fd]) == 1)
			break ;
	}
	free(buffer);
	if (!line[fd] || !line[fd][0])
		return (free(line[fd]), line[fd] = NULL, NULL);
	return_str = fline(line[fd]);
	if (!return_str || return_str[0] == '\0')
		return (free(line[fd]), line[fd] = NULL, NULL);
	return (line[fd] = sline(line[fd]), return_str);
}
