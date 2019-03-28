/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:49:45 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/25 16:17:16 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_newlst	*ft_crealst(t_newlst *lst, const int fd, t_newlst *first_lst)
{
	if (!lst)
	{
		if (!(lst = (t_newlst *)malloc(sizeof(t_newlst))))
			return (NULL);
		lst->fd = fd;
		lst->tail = ft_strnew(0);
		lst->next = NULL;
		lst->first_lst = first_lst;
	}
	return (lst);
}

static t_newlst	*ft_iterlst(t_newlst *lst, const int fd)
{
	t_newlst	*pre;
	t_newlst	*first;

	pre = NULL;
	if (!lst)
	{
		lst = ft_crealst(lst, fd, NULL);
		lst->first_lst = lst;
	}
	first = lst->first_lst;
	lst = first;
	while (lst)
	{
		pre = lst;
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	if (!lst)
		lst = ft_crealst(lst, fd, first);
	if (pre)
		pre->next = lst;
	return (lst);
}

static int		ft_cuttail(char *tail, t_newlst *lst, char **line)
{
	long long	num;

	*line = ft_strnjoinfree(*line, tail);
	if (ft_strchr(tail, '\n'))
	{
		num = ft_strcl(tail, '\n');
		lst->tail = ft_strsub(tail, num + 1, ft_strlen(tail) - num);
		ft_strdel(&tail);
		return (1);
	}
	ft_strdel(&lst->tail);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_newlst *lst;
	char			*buf;
	long long		rea;

	buf = NULL;
	if (fd < 0 || !line || !(*line = ft_strnew(0))
			|| BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	lst = ft_iterlst(lst, fd);
	if (lst->tail && ft_cuttail(lst->tail, lst, line))
		return (1);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((rea = read(lst->fd, buf, BUFF_SIZE)))
	{
		buf[rea] = '\0';
		if (ft_cuttail(buf, lst, line))
			return (1);
		if (rea < BUFF_SIZE)
			return (1);
	}
	return (**line ? 1 : 0);
}
