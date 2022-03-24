/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:46:53 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:47:12 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swaping(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	bubble_sort(int *arry, int n)
{
	int	i;
	int	j;

	j = 0;
	while (j < n)
	{
		i = n - 1;
		while (i > j)
		{
			if (arry[i] < arry[i - 1])
			{
				swaping(&arry[i], &arry[i - 1]);
			}
			i--;
		}
		j++;
	}
}
