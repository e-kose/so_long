/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:38:01 by ekose             #+#    #+#             */
/*   Updated: 2024/02/03 17:58:37 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx(t_so_long *so_long)
{
	int	w;
	int	h;

	so_long->mlx_connect = mlx_init();
	if (so_long->mlx_connect == NULL)
		ft_free(so_long, "Error\nMlx Connection");
	so_long->mlx_window = mlx_new_window(so_long->mlx_connect,
			(so_long->x) * 64, (so_long->y) * 64, "so_long");
	if (so_long->mlx_window == NULL)
		ft_free(so_long, "Error\nWindow failed to open");
	so_long->xpm = malloc(sizeof(t_xpm));
	so_long->xpm->img_0 = mlx_xpm_file_to_image(so_long->mlx_connect,
			"textures/ground.xpm", &w, &h);
	so_long->xpm->img_w = mlx_xpm_file_to_image(so_long->mlx_connect,
			"textures/wall.xpm", &w, &h);
	so_long->xpm->img_p = mlx_xpm_file_to_image(so_long->mlx_connect,
			"textures/player.xpm", &w, &h);
	so_long->xpm->img_e = mlx_xpm_file_to_image(so_long->mlx_connect,
			"textures/exit.xpm", &w, &h);
	so_long->xpm->img_c = mlx_xpm_file_to_image(so_long->mlx_connect,
			"textures/collect.xpm", &w, &h);
}

void	ft_put_image(int i, int j, t_so_long *dt)
{
	if (dt->map_rows[i][j] == '1')
		mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
			dt->xpm->img_w, j * 64, i * 64);
	else if (dt->map_rows[i][j] == '0')
		mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
			dt->xpm->img_0, j * 64, i * 64);
	else if (dt->map_rows[i][j] == 'P')
		mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
			dt->xpm->img_p, j * 64, i * 64);
	else if (dt->map_rows[i][j] == 'C')
		mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
			dt->xpm->img_c, j * 64, i * 64);
	else if (dt->map_rows[i][j] == 'E')
		mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
			dt->xpm->img_e, j * 64, i * 64);
}
