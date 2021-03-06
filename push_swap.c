/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:45:37 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:53:59 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_sorting(t_list *list_a, t_list *list_b)
{
	int	length;

	length = ft_lstsize(list_a);
	if (ft_isduplicated(list_a, length) == 1)
	{
		write(2, "ERROR\n", 6);
		ft_lstclear(&list_a);
		exit(0);
	}
	if (is_sorted_a(list_a) == 1)
	{
		ft_lstclear(&list_a);
		exit(0);
	}
	if (length <= 3)
		sorting_small_list(&list_a);
	else if (length <= 5)
		sorting_medium_list(&list_a, &list_b, length / 2);
	else if (length > 5)
		operation_in_stack_a(&list_a, &list_b, length);
	ft_lstclear(&list_a);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	char	**list;

	if (ac < 2)
		return (0);
	if (check_args(av) == 1)
		return (write(2, "ERROR\n", 6), 0);
	list = get_list(av);
	if (check_if_digit(list) == 1)
		return (write(2, "ERROR\n", 6), 0);
	list_a = creat_list_a(list);
	free_list(list);
	list_b = NULL;
	operations_sorting(list_a, list_b);
	return (0);
}
