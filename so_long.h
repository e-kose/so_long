/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:12:28 by ekose             #+#    #+#             */
/*   Updated: 2024/02/02 16:39:37 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct s_xpm
{
	void	*img_w;
	void	*img_0;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	char	*map;
}	t_xpm;

typedef struct s_so_long
{
	t_xpm		*xpm;
	char		*argv;
	char		**map_rows;
	size_t		x;
	size_t		y;
	void		*mlx_connect;
	void		*mlx_window;
	int			player[2];
	int			exit[2];
	int			fd[6];
	int			movement;
	int			p;
	int			c;
	int			e;

}		t_so_long;

void	ft_error_msg(char *s);
void	ft_perror_msg(char *s);
void	ft_check_map_name(t_so_long *so_long);
void	ft_map_rows(t_so_long *so_long);
void	ft_map_wall(t_so_long *so_long);
void	ft_content_check(t_so_long	*so_long);
void	ft_content_check2(t_so_long *so_long);
void	ft_mlx(t_so_long *so_long);
void	ft_put_image(int i, int j, t_so_long *dt);
int		ft_key(int key_code, t_so_long *so_long);
void	ft_xpm_check(t_so_long *so_long);
void	ft_free(t_so_long *so_long, char *s);
void	ft_image_loop(t_so_long *so_long);
void	ft_cp_map(t_so_long *so_long);
int		ft_full_free(t_so_long *so_long);

#endif
