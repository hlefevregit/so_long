/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:45:15 by marvin            #+#    #+#             */
/*   Updated: 2021/12/20 17:45:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	errors(char *message)
{
	printf("%s\n", "ERROR", message);
	return (0);
}

void	error_null(char *message)
{
	printf("%s\n", "ERROR", message);
	return (0);
}