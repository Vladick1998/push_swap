/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:49:45 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:50:28 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a_and_b(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) > 1 && ft_lstsize(*list_b) > 1)
	{
		swap_a(list_a);
		swap_b(list_b);
		ft_putendl_fd("ss");
	}
}
