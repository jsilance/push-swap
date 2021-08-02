/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:46:11 by jsilance          #+#    #+#             */
/*   Updated: 2021/04/09 00:25:23 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	hasto(char *s, char c)
{
	size_t	to;

	to = 0;
	while (s && s[to])
	{
		if (s[to] == c)
			return (to + 1);
		to++;
	}
	if (s && s[to] == c)
		return (to + 1);
	return (0);
}

static char	*jointo(char *s1, char *s2, char **tofree)
{
	char	*a;
	size_t	sl1;
	size_t	sl2;
	size_t	i;

	a = NULL;
	sl1 = hasto(s1, '\0');
	sl2 = hasto(s2, '\0');
	a = (char *)malloc((sl1 + sl2 + 1) * sizeof(char));
	if (!(a))
	{
		if (tofree && *tofree)
			free(*tofree);
		return (NULL);
	}
	i = 0;
	while (sl1 && s1 && *s1 && *s1 != '\n')
		a[i++] = *s1++;
	while (sl2 && s2 && *s2 && *s2 != '\n')
		a[i++] = *s2++;
	a[i] = '\0';
	if (tofree && *tofree)
		free(*tofree);
	return (a);
}

static int	sub_next_line(int fd, char **line, char *buf)
{
	ssize_t	ret;

	ret = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (-1);
	buf[ret] = '\0';
	*line = jointo(*line, buf, line);
	if (!(*line))
		return (-1);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		ret;
	size_t		i;

	ret = 1;
	i = 0;
	*line = jointo(buf, NULL, NULL);
	if (BUFFER_SIZE < 1 || fd < 0 || !(line) || !(*line))
		return (-1);
	while (!hasto(buf, '\n') && ret)
	{
		ret = sub_next_line(fd, line, buf);
		if (ret < 0)
			return (-1);
	}
	ret = hasto(buf, '\n');
	if (ret == 0)
		return (0);
	while (buf[ret] && ret)
		buf[i++] = buf[ret++];
	buf[i] = '\0';
	return (1);
}
