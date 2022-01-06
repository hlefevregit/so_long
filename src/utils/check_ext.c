/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:08:34 by marvin            #+#    #+#             */
/*   Updated: 2021/12/23 12:08:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_ext(char *argv, char *ext)
{
	int	l_argv;
	int	l_ext;
	int	i;

	l_argv = ft_strlen(argv);
	l_ext = ft_strlen(ext);
	i = 0;
	while (l_ext > 0)
	{
		if (ext[l_ext] == argv[l_argv])
		{
			l_argv--:
			l_ext--;
		}
		else
			return (0);
	}
	return (1);
}