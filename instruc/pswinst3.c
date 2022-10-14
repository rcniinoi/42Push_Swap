/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswinst3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:31:59 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/14 22:15:17 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_hua *hua, int count)
{
	t_stk	*tmp1;
	t_stk	*tmp2;
	t_stk	*tmpfront;
	t_stk	*tmp;
	int		i;

	i = count - 1;
	tmpfront = hua->huaa;
	tmp1 = ft_lstlast2(hua->huaa);
	tmp2 = tmp1->prev;
	if (tmp1 && tmp2 && tmpfront)
	{
		tmp1->next = tmpfront;
		tmpfront->prev = tmp1;
		tmp1->prev = NULL;
		tmp2->next = NULL;
		hua->huaa = tmp1;
		tmp = hua->huaa;
		while (i > 0)
		{
			ft_swapab(&tmp->index, &tmp->next->index);
			tmp = tmp->next;
			i--;
		}
	}
	ft_printf("rra\n");
}

void	ft_rrb(t_hua *hua, int count)
{
	t_stk	*tmp1;
	t_stk	*tmp2;
	t_stk	*tmpfront;
	t_stk	*tmp;
	int		i;

	i = count - 1;
	tmpfront = hua->huab;
	tmp1 = ft_lstlast2(hua->huab);
	tmp2 = tmp1->prev;
	if (tmp1 && tmp2 && tmpfront)
	{
		tmp1->next = tmpfront;
		tmpfront->prev = tmp1;
		tmp1->prev = NULL;
		tmp2->next = NULL;
		hua->huab = tmp1;
		tmp = hua->huab;
		while (i > 0)
		{
			ft_swapab(&tmp->index, &tmp->next->index);
			tmp = tmp->next;
			i--;
		}
	}
	ft_printf("rrb\n");
}

void	ft_rrr(t_hua *hua)
{
	ft_rra(hua, hua->aval);
	ft_rrb(hua, hua->bval);
}
