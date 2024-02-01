/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:49:05 by ekose             #+#    #+#             */
/*   Updated: 2024/02/01 13:14:15 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_extension(t_so_long *so_long)
{
	size_t		i;

	i = ft_strlen(so_long->argv) - 4;
	if (ft_strncmp(&(so_long->argv[i]), ".ber", 4) != 0)
		ft_error_msg("Error\nWrong file extension");
}

void	ft_check_map_name(t_so_long *so_long)
{
	int		fd;
	char	*map_way;

	map_way = ft_strjoin("map/", so_long->argv);
	fd = open(map_way, O_RDONLY);
	if (fd == -1)
		ft_perror_msg("File");
	close(fd);
	free(map_way);
	ft_check_extension(so_long);
}

void	ft_map_wall(t_so_long *so_long)
{
	int		i;
	size_t	j;
	size_t	len;

	i = 0;
	j = -1;
	len = ft_strlen(so_long->map_rows[i]);
	while (so_long->map_rows[++i])
	{
		if (ft_strlen(so_long->map_rows[i]) != len)
			ft_free(so_long, "Error\nThe map is not rectangular");
		if (so_long->map_rows[i][0] != '1' ||
		so_long->map_rows[i][len - 2] != '1')
			ft_free(so_long, "Error\nFirst column last column Wall error");
	}
	if (so_long ->y == len - 1)
		ft_free(so_long, "Error\nThe map is square");
	while (++j < len - 1)
	{
		if ((so_long->map_rows[0][j] != '1' ) ||
		(so_long->map_rows[i - 1][j] != '1'))
			ft_free(so_long, "Error\nFirst line last line Wall error");
	}
}

void	ft_content_check(t_so_long	*so_long)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = so_long->map_rows;
	while (map[++i])
	{
		j = 0;
		while (map[i][j + 1])
		{
			if (map[i][j] == 'C')
				so_long->c++;
			else if (map[i][j] == 'E')
				so_long->e++;
			else if (map[i][j] == 'P')
				so_long->p++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				ft_free(so_long, "Error\nInvalid content");
			j++;
		}
	}
	ft_content_check2(so_long);
}

void	ft_content_check2(t_so_long *so_long)
{
	int	i;
	int	j;

	i = -1;
	if (so_long->e != 1 || so_long->p != 1
		|| so_long->c < 1)
		ft_free(so_long, "Error\nContent totals are incorrect");
	while (so_long->map_rows[++i])
	{
		j = -1;
		while (so_long->map_rows[i][++j])
		{
			if (so_long->map_rows[i][j] == 'P')
			{
				so_long->player[0] = i;
				so_long->player[1] = j;
			}
			if (so_long->map_rows[i][j] == 'E')
			{
				so_long->exit[0] = i;
				so_long->exit[1] = j;
			}
		}
	}
}
