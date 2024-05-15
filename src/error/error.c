/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:41:24 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:41:24 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	errors(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	return (0);
}

void	*error_null(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	return (0);
}
