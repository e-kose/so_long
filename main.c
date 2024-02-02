/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:11:53 by ekose             #+#    #+#             */
/*   Updated: 2024/02/02 16:40:47 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	*so_long;

	if (argc != 2)
		ft_error_msg("number of invalid arguments");
	so_long = malloc(sizeof(t_so_long));
	if (so_long == NULL)
		ft_error_msg("So_long not alloceted");
	so_long->argv = argv[1];
	so_long->movement = 0;
	so_long->e = 0;
	so_long->p = 0;
	so_long->c = 0;
	ft_check_map_name(so_long);
	ft_map_rows(so_long);
	ft_map_wall(so_long);
	ft_content_check(so_long);
	ft_cp_map(so_long);
	ft_xpm_check(so_long);
	ft_image_loop(so_long);
	mlx_key_hook(so_long->mlx_window, ft_key, so_long);
	mlx_hook(so_long->mlx_window, 17, 0, ft_full_free, so_long);
	mlx_loop(so_long->mlx_connect);

}
