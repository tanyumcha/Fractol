/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:48:37 by mernser           #+#    #+#             */
/*   Updated: 2019/06/08 14:46:51 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_shred(char **cut, char **left, char **right)
{
	char		*x;
	int			sub;

	if ((x = ft_strchr(*cut, '\n')) != NULL)
	{
		if (!(*left = ft_strsub(*cut, 0, (x - *cut))))
			return (0);
		sub = x + 1 - *cut;
		if (!(*right = ft_strsub(*cut, sub, ft_strlen(*cut) - sub)))
			return (0);
		ft_strdel(cut);
		return (1);
	}
	*left = *cut;
	return (-1);
}

static	void	ft_kek(char **ptr, char **tmp, char **line, char **join)
{
	if (*ptr != NULL)
		ft_strdel(ptr);
	else
		ft_strdel(tmp);
	*line = *join;
	*tmp = *join;
}

static int		ft_read(char **line, char **ptr, int fd, int *f)
{
	char		tab[BUFF_SIZE + 1];
	char		*tmp;
	char		*temp_tab;
	char		*join;
	int			red;

	tmp = *ptr;
	while ((red = read(fd, tab, BUFF_SIZE)) > 0)
	{
		*f = 3;
		if ((tab[red] = '\0') || !(ft_strchr(tab, '\n')))
		{
			if (!(join = ft_strjoin(tmp, tab)))
				return (-1);
			ft_kek(ptr, &tmp, line, &join);
			continue ;
		}
		if (!(temp_tab = ft_strjoin(tmp, tab)))
			return (-1);
		ft_strdel(&tmp);
		if (!(ft_shred(&temp_tab, &tmp, ptr)) || !(*line = tmp))
			return (-1);
		return (red);
	}
	return (red);
}

int				get_next_line(const int fd, char **line)
{
	static char	*ptr[10240];
	int			red;
	int			f;
	char		*tmp;

	if (fd < 0 || fd >= 10240 || BUFF_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (-1);
	if ((f = 2) && ptr[fd])
	{
		if (!(f = ft_shred(&ptr[fd], line, &tmp)))
			return (-1);
		if (f != -1 && (ptr[fd] = tmp))
			return (1);
	}
	tmp = ptr[fd];
	if ((red = ft_read(line, &ptr[fd], fd, &f)) == -1)
		return (-1);
	if (ptr[fd] == tmp && f == -1 && ptr[fd][0] == '\0' && red == 0)
	{
		ft_strdel(&ptr[fd]);
		return (0);
	}
	if (ptr[fd] == tmp && f == -1)
		ptr[fd] = NULL;
	return ((red == 0 && f == 2) ? 0 : 1);
}
