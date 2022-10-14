/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswinst2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:37:41 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/15 02:48:26 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_hua	*hua, int mode)
{
	int		i;
	int		j;
	t_stk	*tmp;

	i = hua->aval;
	j = hua->bval - 1;
	tmp = hua->huaa;
	while (i-- > 0)
	{
		tmp->index += 1;
		tmp = tmp->next;
	}
	if (hua->huab)
		ft_push(hua, hua->huab, hua->huaa, 1);
	tmp = hua->huab;
	while (j-- > 0)
	{
		tmp->index -= 1;
		tmp = tmp->next;
	}
	hua->aval += 1;
	hua->bval -= 1;
	if (mode == 1)
		ft_dprintf(1, "pa\n");
}

void	ft_pb(t_hua	*hua, int mode)
{
	int		i;
	int		j;
	t_stk	*tmp;

	i = hua->bval;
	j = hua->aval - 1;
	tmp = hua->huab;
	while (i-- > 0)
	{
		tmp->index += 1;
		tmp = tmp->next;
	}
	if (hua->huaa)
		ft_push(hua, hua->huaa, hua->huab, 2);
	tmp = hua->huaa;
	while (j-- > 0)
	{
		tmp->index -= 1;
		tmp = tmp->next;
	}
	hua->bval += 1;
	hua->aval -= 1;
	if (mode == 1)
		ft_dprintf(1, "pb\n");
}

void	ft_rr(t_hua	*hua)
{
	ft_ra(hua, hua->aval, 2);
	ft_rb(hua, hua->bval, 2);
	ft_dprintf(1, "rr\n");
}
