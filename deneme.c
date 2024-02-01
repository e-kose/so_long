// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>

// int main(){

//     int i=0;
//     int readed=1;
//     int sayi = 0;
//     char *buf;
//     int fd = open("map/a.txt",O_RDONLY);
//     while(readed)
//     {
//         readed=read(fd,buf,1);
//         i++;
//     }
//     i--;
//     while(i>=0)
//     {
//         if(buf[i]=='\n')
//             sayi++;
//         i--;
//     }
// }
// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include "GNL/get_next_line.h"

// int main() {
//     char *p;
//     int i;
//     i = 0;
//     int j;
//     int fd = open("map/a.ber",O_RDONLY);
//     p = get_next_line(fd);
//     i++;
//     while(p)
//     {
//         free(p);
//         p=get_next_line(fd);
//         i++;
//     }
//     i--;

// }


// void	ft_put_image(t_so_long *dt)
// {
// 	// int	i;
// 	// int	j;

// 	// i = -1;
// 	// while (dt->map_rows[++i])
// 	// {
// 	// 	j = -1;
// 	// 	while (dt->map_rows[i][++j])
// 	// 	{
// 			if (dt->map_rows[i][j] == '1')
// 				mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
// 					dt->xpm->img_w, j * 64, i * 64);
// 			else if (dt->map_rows[i][j] == '0')
// 				mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
// 					dt->xpm->img_0, j * 64, i * 64);
// 			else if (dt->map_rows[i][j] == 'P')
// 				mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
// 					dt->xpm->img_p, j * 64, i * 64);
// 			else if (dt->map_rows[i][j] == 'C')
// 				mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,
// 					dt->xpm->img_c, j * 64, i * 64);
// 			else if (dt->map_rows[i][j] == 'E')
// 				mlx_put_image_to_window(dt->mlx_connect, dt->mlx_window,dt->xpm->img_e,
// 				 j * 64, i * 64);
// 	// 	}
// 	// }
// }
