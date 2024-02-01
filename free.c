/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:32:49 by ekose             #+#    #+#             */
/*   Updated: 2024/02/01 12:48:36 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_so_long *so_long, char *s)
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
	ft_error_msg(s);
}
