/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:50:50 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:53:59 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_list **list_b)
{
	int	temp;

	if (ft_lstsize(*list_b) > 1)
	{
		temp = (*list_b)->content;
		ft_lstadd_back(list_b, ft_lstnew(temp));
		ft_lstdelone(list_b);
		ft_putendl_fd("rb");
	}
}

void	reverse_rotate_a(t_list **list_a)
{
	t_list	*temp;
	t_list	*lst;

	if (ft_lstsize(*list_a) > 1)
	{
		temp = ft_lstlast(*list_a);
		lst = *list_a;
		while (lst->next->next)
			lst = lst->next;
		lst->next = NULL;
		ft_lstadd_front(list_a, temp);
		ft_putendl_fd("rra");
	}
}

void	reverse_rotate_b(t_list **list_b)
{
	t_list	*temp;
	t_list	*lst;

	if (ft_lstsize(*list_b) > 1)
	{
		temp = ft_lstlast(*list_b);
		lst = *list_b;
		while (lst->next->next)
			lst = lst->next;
		lst->next = NULL;
		ft_lstadd_front(list_b, temp);
		ft_putendl_fd("rrb");
	}
}

void	rverse_rotate_a_and_b(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) > 1 && ft_lstsize(*list_b) > 1)
	{
		reverse_rotate_a(list_a);
		reverse_rotate_b(list_b);
		ft_putendl_fd("rrr");
	}
}

void	rotate_a_and_b(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) > 1 && ft_lstsize(*list_b) > 1)
	{
		rotate_a(list_a);
		rotate_b(list_b);
		ft_putendl_fd("rr");
	}
}
