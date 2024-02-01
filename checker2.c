/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:47:08 by ekose             #+#    #+#             */
/*   Updated: 2024/02/01 17:48:32 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_close(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i <= 6)
		close(so_long->fd[i++]);
}

void	ft_flood_fill(t_so_long *so_long)
{
	i
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

int	ft_close_window(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->y)
	{
		free(so_long->map_rows[i]);
		i++;
	}
	free(so_long->map_rows);
	free(so_long);
	mlx_destroy_window(so_long->mlx_connect, so_long->mlx_window);
	exit(0);
}
