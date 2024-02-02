/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:12:20 by ekose             #+#    #+#             */
/*   Updated: 2024/02/02 15:55:02 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_go_up(t_so_long *dt)
{
	char	*value;

	if (dt->map_rows[dt->player[0] - 1][dt->player[1]] != '1')
	{
		dt->movement++;
		write (1, "Movement = ", 11);
		ft_putnbr_fd(dt->movement, 1);
		write (1, " ⬆️\n", 9);
		if (dt->map_rows[dt->player[0] - 1][dt->player[1]] == 'C')
			dt->c--;
		else if (dt->map_rows[dt->player[0] - 1][dt->player[1]] == 'E' &&
		dt->c == 0)
		{
			write (1, "🎉Congratulations on a successful game 🎉", 46);
			ft_full_free(dt);
		}
		mlx_clear_window(dt->mlx_connect, dt->mlx_window);
		dt->map_rows[dt->player[0]][dt->player[1]] = '0';
		dt->player[0]--;
		dt->map_rows[dt->player[0]][dt->player[1]] = 'P';
		ft_image_loop(dt);
	}
}

void	ft_go_down(t_so_long *dt)
{
	char	*value;

	if (dt->map_rows[dt->player[0] + 1][dt->player[1]] != '1')
	{
		dt->movement++;
		write (1, "Movement = ", 11);
		ft_putnbr_fd(dt->movement, 1);
		write (1, " ⬇️\n", 9);
		if (dt->map_rows[dt->player[0] + 1][dt->player[1]] == 'C')
			dt->c--;
		else if (dt->map_rows[dt->player[0] + 1][dt->player[1]] == 'E' &&
		dt->c == 0)
		{
			write (1, "🎉Congratulations on a successful game 🎉", 46);
			ft_full_free(dt);
		}
		mlx_clear_window(dt->mlx_connect, dt->mlx_window);
		dt->map_rows[dt->player[0]][dt->player[1]] = '0';
		dt->player[0]++;
		dt->map_rows[dt->player[0]][dt->player[1]] = 'P';
		ft_image_loop(dt);
	}
}

void	ft_go_right(t_so_long *dt)
{
	char	*value;

	if (dt->map_rows[dt->player[0]][dt->player[1] + 1] != '1')
	{
		dt->movement++;
		write (1, "Movement = ", 11);
		ft_putnbr_fd(dt->movement, 1);
		write(1, " ⏩\n", 6);
		if (dt->map_rows[dt->player[0]][dt->player[1] + 1] == 'C')
			dt->c--;
		else if (dt->map_rows[dt->player[0]][dt->player[1] + 1] == 'E' &&
		dt->c == 0)
		{
			write (1, "🎉Congratulations on a successful game 🎉", 46);
			ft_full_free(dt);
		}
		mlx_clear_window(dt->mlx_connect, dt->mlx_window);
		dt->map_rows[dt->player[0]][dt->player[1]] = '0';
		dt->player[1]++;
		dt->map_rows[dt->player[0]][dt->player[1]] = 'P';
		ft_image_loop(dt);
	}
}

void	ft_go_left(t_so_long *dt)
{
	char	*value;

	if (dt->map_rows[dt->player[0]][dt->player[1] - 1] != '1')
	{
		dt->movement++;
		write (1, "Movement = ", 11);
		ft_putnbr_fd(dt->movement, 1);
		write (1, " ⬅️\n", 9);
		if (dt->map_rows[dt->player[0]][dt->player[1] - 1] == 'C')
			dt->c--;
		else if (dt->map_rows[dt->player[0]][dt->player[1] - 1] == 'E' &&
		dt->c == 0)
		{
			write (1, "🎉Congratulations on a successful game 🎉", 46);
			ft_full_free(dt);
		}
		mlx_clear_window(dt->mlx_connect, dt->mlx_window);
		dt->map_rows[dt->player[0]][dt->player[1]] = '0';
		dt->map_rows[dt->player[0]][dt->player[1] - 1] = '0';
		ft_image_loop(dt);
		dt->player[1]--;
		dt->map_rows[dt->player[0]][dt->player[1]] = 'P';
	}
}

int	ft_key(int key_code, t_so_long *so_long)
{
	if (key_code == 13 || key_code == 126 || key_code == 119)
		ft_go_up(so_long);
	else if (key_code == 1 || key_code == 125|| key_code == 115)
		ft_go_down(so_long);
	else if (key_code == 2 || key_code == 124|| key_code == 100)
		ft_go_right(so_long);
	else if (key_code == 0 || key_code == 123|| key_code == 97)
		ft_go_left(so_long);
	else if (key_code == 53 || key_code == 65307)
		ft_full_free(so_long);
	if (so_long->player[0] == so_long->exit[0]
		&& so_long->player[1] == so_long->exit[1])
	{
		mlx_clear_window(so_long->mlx_connect, so_long->mlx_window);
		so_long->map_rows[so_long->exit[0]][so_long->exit[1]] = 'E';
		ft_image_loop(so_long);
		so_long->map_rows[so_long->player[0]][so_long->player[1]] = 'P';
	}
	else
		so_long->map_rows[so_long->exit[0]][so_long->exit[1]] = 'E';
	ft_image_loop(so_long);
	return (0);
}



