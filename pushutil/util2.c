/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:34:14 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 16:34:15 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_chksworded(t_hua *hua)
{
	t_stk	*tmp;

	tmp = hua->huaa;
	while (tmp->next != NULL)
	{
		if (tmp->index == tmp->realdex)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	ft_lekrieng(t_hua *hua)
{
	t_stk	*tmp;

	tmp = hua->huaa;
	while (tmp->next != NULL)
	{
		if (tmp->realdex == tmp->next->realdex - 1)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	ft_huaini(t_hua *hua, t_array *ray, int count)
{
	hua->aval = count;
	hua->bval = 0;
	hua->huaa = ft_stkabini(ray->realarray, count);
	hua->huab = NULL;
}

void	ft_rayini(t_array *ray)
{
	ray->charbuffer = NULL;
	ray->fakearray = NULL;
	ray->realarray = NULL;
}
