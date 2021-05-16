/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:25:57 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 19:39:49 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_start_point(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

int		get_end_point(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	size_t s1_len;

	i = 0;
	j = 0;
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (set[j] != '\0')
	{
		if (s1[s1_len - i - 1] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (s1_len - i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	if (get_end_point(s1, set) < get_start_point(s1, set))
		len = 0;
	else
		len = get_end_point(s1, set) - get_start_point(s1, set) + 1;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[get_start_point(s1, set) + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
