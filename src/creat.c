/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:47:43 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:47:49 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*creat_list_a(char **av)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
		{
			free_list(av);
			write (2, "ERROR\n", 6);
			exit (0);
		}
		i++;
	}
	i = 1;
	temp = ft_lstnew(ft_atoi(av[0]));
	temp->next = NULL;
	while (av[i])
	{
		ft_lstadd_back(&temp, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (temp);
}

char	**get_list(char **av)
{
	char	*string;
	char	*arg;
	char	**list;
	int		i;

	i = 1;
	string = malloc(sizeof(char));
	if (string == NULL)
		return (NULL);
	string[0] = '\0';
	while (av[i])
	{
		arg = ft_strjoin(string, av[i]);
		free(string);
		string = ft_strjoin(arg, " ");
		free(arg);
		i++;
	}
	list = ft_split(string, ' ');
	free(string);
	string = NULL;
	return (list);
}
