/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:49:19 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/03/24 14:53:59 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_countwords(char const *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static void	ft_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		free(temp[i++]);
	exit (1);
}

static char	*ft_write(char *word, char const *str, int k, int letters)
{
	int	i;
	int	x;

	i = 0;
	x = k - letters;
	while (i < letters)
		word[i++] = str[x++];
	word[i] = '\0';
	return (word);
}

static void	ft_tempsplit(char **temp, char const *str, char c, int words)
{
	int		i;
	int		k;
	int		letters;

	i = 0;
	k = 0;
	letters = 0;
	while (str[i] && k < words)
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			letters++;
		}
		temp[k] = (char *)malloc(sizeof(char) * (letters + 1));
		if (temp == NULL)
			ft_free(temp);
		ft_write(temp[k], str, i, letters);
		letters = 0;
		k++;
	}
	temp[k] = 0;
}

char	**ft_split(char const *str, char c)
{
	int		words;
	char	**temp;

	if (str == NULL)
		return (NULL);
	temp = NULL;
	words = ft_countwords(str, c);
	temp = (char **)malloc(sizeof(char *) * (words + 1));
	if (temp == NULL)
		return (NULL);
	ft_tempsplit(temp, str, c, words);
	return (temp);
}
