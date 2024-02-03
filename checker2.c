/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:47:08 by ekose             #+#    #+#             */
/*   Updated: 2024/02/03 13:37:21 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_check_way(t_so_long *so_long, char **map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E'))
				check = 1;
		}
		free(map[i]);
		i++;
	}
	free(map);
	if (check == 1)
		ft_free(so_long, "no valid road on the map");
}

static void	ft_close(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i <= 6)
		close(so_long->fd[i++]);
}

static void	ft_flood_fill(char	**map, int i, int j)
{
	if (i < 1 || j < 1 || map[i][j] == '1')
		return ;
	map[i][j] = '1';
	ft_flood_fill(map, i + 1, j);
	ft_flood_fill(map, i - 1, j);
	ft_flood_fill(map, i, j + 1);
	ft_flood_fill(map, i, j - 1);
}

void	ft_xpm_check(t_so_long *so_long)
{
	so_long->fd[0] = open("textures/", O_RDONLY);
	if (so_long->fd[0] == -1)
		ft_perror_msg("Textures");
	so_long->fd[1] = open("textures/exit.xpm", O_RDONLY);
	if (so_long->fd[1] == -1)
		ft_perror_msg("Textures/exit");
	so_long->fd[2] = open("textures/wall.xpm", O_RDONLY);
	if (so_long->fd[2] == -1)
		ft_perror_msg("Textures/wall");
	so_long->fd[3] = open("textures/ground.xpm", O_RDONLY);
	if (so_long->fd[3] == -1)
		ft_perror_msg("Textures/ground");
	so_long->fd[4] = open("textures/collect.xpm", O_RDONLY);
	if (so_long->fd[4] == -1)
		ft_perror_msg("Textures/collect");
	so_long->fd[5] = open("textures/player.xpm", O_RDONLY);
	if (so_long->fd[5] == -1)
		ft_perror_msg("Textures/player");
	ft_close(so_long);
	ft_mlx(so_long);
}

void	ft_cp_map(t_so_long *so_long)
{
	int		i;
	int		check;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (so_long->y + 1));
	i = 0;
	check = 0;
	while (so_long->map_rows[i])
	{
		map[i] = ft_strdup(so_long->map_rows[i]);
		i++;
	}
	map[i] = NULL;
	ft_flood_fill(map, so_long->player[0], so_long->player[1]);
	ft_check_way(so_long, map);
}
