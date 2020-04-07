/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:19:17 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/02 10:22:11 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclr(t_list **begin_list)
{
	t_list *tmp;

	if (!(*begin_list))
		return ;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
}
