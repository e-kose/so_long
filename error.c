/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:26:28 by ekose             #+#    #+#             */
/*   Updated: 2024/02/01 12:42:11 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(char *s)
{
	write(2, s, ft_strlen(s));
	system("leaks a.out");
	exit(1);
}

void	ft_perror_msg(char *s)
{
	perror(s);
	system("leaks a.out");
	exit(1);
}
