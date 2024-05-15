/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:43:26 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/15 15:28:13 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	s = malloc(size * count);
	if (!s)
		return (0);
	ft_memset(s, 0, count * size);
	return (s);
}
