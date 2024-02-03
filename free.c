/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:32:49 by ekose             #+#    #+#             */
/*   Updated: 2024/02/03 12:46:57 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_so_long *so_long, char *s)
{
	int	i;

	i = 0;
	while (so_long->map_rows[i])
	{
		free(so_long->map_rows[i]);
		i++;
	}
	free(so_long->map_rows);
	free(so_long);
	ft_error_msg(s);
}

int	ft_full_free(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (so_long->map_rows[i])
	{
		free(so_long->map_rows[i]);
		i++;
	}
	free(so_long->map_rows);
	mlx_destroy_image(so_long->mlx_connect, so_long->xpm->img_0);
	mlx_destroy_image(so_long->mlx_connect, so_long->xpm->img_w);
	mlx_destroy_image(so_long->mlx_connect, so_long->xpm->img_p);
	mlx_destroy_image(so_long->mlx_connect, so_long->xpm->img_e);
	mlx_destroy_image(so_long->mlx_connect, so_long->xpm->img_c);
	mlx_destroy_window(so_long->mlx_connect, so_long->mlx_window);
	free(so_long->xpm);
	free(so_long->mlx_connect);
	free(so_long);
	exit(0);
}
