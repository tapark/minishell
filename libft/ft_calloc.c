/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sulee <sulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:09:50 by sulee             #+#    #+#             */
/*   Updated: 2021/05/06 20:57:25 by sulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *tmp;

	if (!(tmp = (void *)malloc(count * size)))
		return (NULL);
	ft_memset(tmp, 0, count * size);
	return (tmp);
}