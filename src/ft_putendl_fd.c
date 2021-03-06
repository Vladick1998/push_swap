/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:48:49 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:53:59 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putendl_fd(char *s)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
