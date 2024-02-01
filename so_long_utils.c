/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:14:15 by ekose             #+#    #+#             */
/*   Updated: 2024/02/01 12:56:06 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_total_row(t_so_long *so_long)
{
	char	*p;
	size_t	i;
	int		fd;
	char	*map_way;

	i = 0;
	map_way = ft_strjoin("map/", so_long->argv);
	fd = open(map_way, O_RDONLY);
	p = get_next_line(fd);
	so_long->x = ft_strlen(p) - 1;
	i++;
	while (p)
	{
		free(p);
		p = get_next_line(fd);
		i++;
	}
	so_long->y = --i;
	free(p);
	free(map_way);
	if (so_long->x >= 128 || so_long->y >= 128)
		ft_error_msg("Map size isn't compatiable with mlx library.");
	close(fd);
}

void	ft_map_rows(t_so_long *so_long)
{
	size_t	i;
	int		fd;
	char	*map_way;

	i = 0;
	ft_total_row(so_long);
	map_way = ft_strjoin("map/", so_long->argv);
	fd = open(map_way, O_RDONLY);
	free(map_way);
	if (fd == -1)
		ft_perror_msg(so_long->argv);
	so_long->map_rows = (char **)malloc(sizeof(char *) * (so_long->y + 1));
	if (so_long->map_rows == NULL)
		ft_perror_msg("Malloc");
	while (i < so_long->y)
	{
		so_long->map_rows[i] = get_next_line(fd);
		i++;
	}
	so_long->map_rows[i] = NULL;
}

void	ft_image_loop(t_so_long *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (so_long->map_rows[++i])
	{
		j = -1;
		while (so_long->map_rows[i][++j])
		{
			ft_put_image(i, j, so_long);
		}
	}
}
