/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:51:08 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:51:23 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **list_a)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*list_a) > 1)
	{
		temp = (*list_a)->next;
		swap = temp->content;
		temp->content = (*list_a)->content;
		(*list_a)->content = swap;
		ft_putendl_fd("sa");
	}
}

void	swap_b(t_list **list_b)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*list_b) > 1)
	{
		temp = (*list_b)->next;
		swap = temp->content;
		temp->content = (*list_b)->content;
		(*list_b)->content = swap;
		ft_putendl_fd("sb");
	}
}

void	push_a(t_list **list_a, t_list **list_b)
{
	int	temp;

	if (ft_lstsize(*list_b) > 0)
	{
		temp = (*list_b)->content;
		ft_lstadd_front(list_a, ft_lstnew(temp));
		ft_lstdelone(list_b);
		ft_putendl_fd("pa");
	}
}

void	push_b(t_list **list_b, t_list **list_a)
{
	int	temp;

	if (ft_lstsize(*list_a) > 0)
	{
		temp = (*list_a)->content;
		if (*list_b == NULL)
			*list_b = ft_lstnew(temp);
		else
			ft_lstadd_front(list_b, ft_lstnew(temp));
		ft_lstdelone(list_a);
		ft_putendl_fd("pb");
	}
}

void	rotate_a(t_list **list_a)
{
	int	temp;

	if (ft_lstsize(*list_a) > 1)
	{
		temp = (*list_a)->content;
		ft_lstadd_back(list_a, ft_lstnew(temp));
		ft_lstdelone(list_a);
		ft_putendl_fd("ra");
	}
}
