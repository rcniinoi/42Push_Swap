/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswsolve3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:08:58 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 23:41:49 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_atob3(t_hua *hua, int count, int times)
{
	int	p;
	int	m;

	m = 0;
	p = (((count - 3) - (count % times)) / times);
	if (p == 0)
		p++;
	while (hua->aval > 3)
	{
		while (hua->bval <= (p * m) \
			+ p && hua->aval > 3)
		{
			if (hua->huaa->realdex <= (p * m) \
				+ p && hua->huaa->realdex < count - 3)
			{
				ft_pb(hua, 1);
				if (hua->huab->realdex <= ((p * m) + p) - (p / 2))
					ft_rb(hua, hua->bval, 1);
			}
			else
				ft_ra(hua, hua->aval, 1);
		}
		m++;
	}
	ft_sortsammlast3(hua, count);
}

void	ft_sortsammlast3(t_hua *hua, int count)
{
	if (hua->huaa->next->next->realdex == count - 1)
	{
		if (hua->huaa->next->realdex == count - 3)
			ft_sa(hua, 1);
	}
	if (hua->huaa->next->next->realdex == count - 2)
	{
		if (hua->huaa->realdex < hua->huaa->next->realdex)
			ft_sa(hua, 1);
		ft_ra(hua, hua->aval, 1);
	}
	if (hua->huaa->next->next->realdex == count - 3)
	{
		if (hua->huaa->realdex > hua->huaa->next->realdex)
			ft_sa(hua, 1);
		ft_rra(hua, hua->aval, 1);
	}
}

void	ft_btoa3(t_hua *hua, int count)
{
	int		now;
	t_stk	*tmpb;
	int		yone;
	t_stk	*tmpfind;

	now = count - 4;
	yone = 0;
	while (hua->bval)
	{
		tmpfind = hua->huab;
		tmpb = ft_lstlast2(hua->huab);
		ft_movepaornot(hua, now, tmpfind, tmpb);
		if (hua->huaa->realdex == (now - 2) && ft_lekrieng(hua) == 0)
			yone = ft_doreturnyone(hua, yone, 1);
		if (yone == 0 && hua->huaa->realdex == now \
			&& hua->huaa->next->realdex == (now - 1))
			ft_sa(hua, 1);
		else if (yone == 1 && hua->huaa->realdex == \
			(now - 1) && hua->huaa->next->realdex == now)
			yone = ft_doreturnyone(hua, yone, 2);
		else if (ft_gaeconditionnorm(yone, hua, now) == 1)
			yone = ft_doreturnyone(hua, yone, 3);
		if (ft_lekrieng(hua) == 1)
			now = count - hua->aval - 1;
	}
}

int	ft_doreturnyone(t_hua *hua, int yone, int mode)
{
	if (mode == 1)
	{
		ft_ra(hua, hua->aval, 1);
		yone = 1;
	}
	else if (mode == 2)
	{
		ft_rra(hua, hua->aval, 1);
		yone = 0;
	}
	else if (mode == 3)
	{
		ft_sa(hua, 1);
		ft_rra(hua, hua->aval, 1);
		yone = 0;
	}
	return (yone);
}

void	ft_tmpfindmove(t_hua *hua, t_stk *tmpfind, int now)
{
	while (tmpfind->realdex < (now - 2))
		tmpfind = tmpfind->next;
	if (tmpfind->index <= hua->bval / 2)
		ft_rb(hua, hua->bval, 1);
	else if (tmpfind->index > hua->bval / 2)
		ft_rrb(hua, hua->bval, 1);
}
