/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:52:27 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:54:18 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57) && c != '-' && c != '+')
		return (0);
	else
		return (1);
}

int	check_if_digit(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if (ft_isdigit(list[i][j]) == 0 || (ft_isdigit(list[i][j]) == 1
				&& (list[i][j + 1] == '-' || list[i][j + 1] == '+')))
				return (free_list(list), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isduplicated(t_list *list, int len)
{
	int	*arry;
	int	i;

	i = 0;
	arry = malloc(sizeof(int) * len);
	if (!arry)
		exit(1);
	while (list)
	{
		arry[i++] = list->content;
		list = list->next;
	}
	bubble_sort(arry, len);
	i = 0;
	while (i < len)
	{
		if (arry[i] == arry[i + 1])
			return (free(arry), 1);
		i++;
	}
	return (free(arry), -1);
}

int	is_sorted_a(t_list *list_a)
{
	while (list_a->next)
	{
		if (list_a->content > list_a->next->content)
			return (-1);
		list_a = list_a->next;
	}
	return (1);
}

int	is_sorted_b(t_list *list_b)
{
	while (list_b->next)
	{
		if (list_b->content < list_b->next->content)
			return (-1);
		list_b = list_b->next;
	}
	return (1);
}
