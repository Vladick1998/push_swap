/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:52:06 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:52:10 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting_small_list(t_list **list_a)
{
	if ((*list_a)->content > (*list_a)->next->content)
		swap_a(list_a);
	if (ft_lstsize(*list_a) > 2)
	{
		if ((*list_a)->next->content > (*list_a)->next->next->content)
			reverse_rotate_a(list_a);
		if ((*list_a)->content > (*list_a)->next->content)
			swap_a(list_a);
	}
}

void	sorting_medium_list(t_list **list_a,
			t_list **list_b, int limit)
{
	int	position;
	int	i;

	i = 0;
	while (i++ < limit)
	{
		position = search(*list_a, find_min_value(*list_a));
		if (position <= 2)
		{
			while (search((*list_a), find_min_value(*list_a)))
				rotate_a(list_a);
		}
		else
		{
			while (position > 2 && search(*list_a, find_min_value(*list_a)))
				reverse_rotate_a(list_a);
		}
		if (search(*list_a, find_min_value(*list_a)) == 0)
			push_b(list_b, list_a);
	}
	sorting_small_list(list_a);
	i = 0;
	while (i++ < limit)
		push_a(list_a, list_b);
}

void	sort_rev_ord(t_list **list_b, t_list **list_a, int len)
{
	if (len == 1)
		push_a(list_a, list_b);
	else if (len == 2)
	{
		if ((*list_b)->content < (*list_b)->next->content)
			swap_b(list_b);
		while (len--)
			push_a(list_a, list_b);
	}
	else if (len == 3)
	{
		if ((*list_b)->content < (*list_b)->next->content)
			swap_b(list_b);
		if ((*list_b)->next->content < (*list_b)->next->next->content)
		{
			rotate_b(list_b);
			swap_b(list_b);
			reverse_rotate_b(list_b);
		}
		if ((*list_b)->content < (*list_b)->next->content)
			swap_b(list_b);
		while (len--)
			push_a(list_a, list_b);
	}
}
