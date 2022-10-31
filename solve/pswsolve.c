/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswsolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:41:10 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 16:06:20 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_indexsort(t_hua *hua, t_array *ray, int count)
{
	int		i;
	t_stk	*tmp;

	i = 0;
	while (hua->aval > 3 && i < count)
	{
		tmp = hua->huaa;
		while (tmp->lek != ray->fakearray[i])
			tmp = tmp->next;
		if (tmp->index <= (hua->aval - (hua->aval % 2)) / 2)
			ft_sortbonorlang(hua, ray, i, 1);
		if (tmp->index > (hua->aval - (hua->aval % 2)) / 2)
			ft_sortbonorlang(hua, ray, i, 2);
		i++;
	}
	ft_sortsammlast(hua, ray, count);
	while (hua->bval > 0)
	{
		ft_pa(hua, 1);
	}
}

void	ft_sortsammlast(t_hua *hua, t_array *ray, int count)
{
	if (hua->huaa->next->next->lek == ray->fakearray[count - 1])
	{
		if (hua->huaa->next->lek == ray->fakearray[count - 3])
			ft_sa(hua, 1);
	}
	if (hua->huaa->next->next->lek == ray->fakearray[count - 2])
	{
		if (hua->huaa->lek < hua->huaa->next->lek)
			ft_sa(hua, 1);
		ft_ra(hua, hua->aval, 1);
	}
	if (hua->huaa->next->next->lek == ray->fakearray[count - 3])
	{
		if (hua->huaa->lek > hua->huaa->next->lek)
			ft_sa(hua, 1);
		ft_rra(hua, hua->aval, 1);
	}
}

void	ft_atob(t_hua *hua, t_array *ray, int count, int times)
{
	int	par;
	int	i;
	int	mul;

	i = times - 1;
	par = ((count - 3) - ((count - 3) % times)) / times;
	while (hua->aval > 3)
	{
		mul = par * i;
		while (hua->aval > mul + 3 && hua->aval > 3)
		{
			if (hua->huaa->lek <= ray->fakearray[(count - mul) - 4])
				ft_pb(hua, 1);
			else
				ft_ra(hua, hua->aval, 1);
		}
		i--;
	}
	ft_sortsammlast(hua, ray, count);
}
