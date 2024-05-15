/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:43:43 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:43:43 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_ext(char *argv, char *ext)
{
	int	l_argv;
	int	l_ext;

	l_argv = ft_strlen(argv);
	l_ext = ft_strlen(ext);
	while (l_ext > 0)
	{
		if (ext[l_ext] == argv[l_argv])
		{
			l_argv--;
			l_ext--;
		}
		else
			return (0);
	}
	return (1);
}
