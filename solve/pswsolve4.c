/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswsolve4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:50:10 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 23:42:38 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sortbonorlang(t_hua *hua, t_array *ray, int i, int mode)
{
	if (mode == 1)
	{
		while (hua->huaa->lek != ray->fakearray[i])
			ft_ra(hua, hua->aval, 1);
		ft_pb(hua, 1);
	}
	if (mode == 2)
	{
		while (hua->huaa->lek != ray->fakearray[i])
			ft_rra(hua, hua->aval, 1);
		ft_pb(hua, 1);
	}
}

void	ft_sbpa(t_hua *hua)
{
	ft_sb(hua, 1);
	ft_pa(hua, 1);
}

void	ft_movepaornot(t_hua *hua, int now, t_stk *tmpfind, t_stk *tmpb)
{
	if (hua->huab->realdex >= (now - 2))
		ft_pa(hua, 1);
	else if (tmpb->realdex >= (now - 2))
		ft_rrbpa(hua);
	else
		ft_tmpfindmove(hua, tmpfind, now);
}

int	ft_gaeconditionnorm(int yone, t_hua *hua, int now)
{
	if (yone == 1 && hua->huaa->realdex == \
		now && hua->huaa->next->realdex == (now - 1))
		return (1);
	else
		return (0);
}
