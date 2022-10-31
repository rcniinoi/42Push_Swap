/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswlstmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:35:57 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 16:32:18 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stk	*ft_lstaddklang(t_stk *front, t_stk *back)
{
	t_stk	*tmp;
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	ft_t_stkini(new);
	if (front)
	{
		tmp = ft_lstlast2(front);
		tmp->next = new;
		new->prev = tmp;
	}
	new->next = back;
	if (back)
		back->prev = new;
	tmp = ft_lstfirst(new);
	return (tmp);
}

void	ft_t_stkini(t_stk *new)
{
	new->lek = 0;
	new->index = 0;
	new->prev = NULL;
	new->next = NULL;
}

void	ft_huastarter(t_hua *hua, int count)
{
	hua->aval = count;
	hua->bval = 0;
}

void	ft_realindexini(t_stk *stk, t_array *ray, int count)
{
	int		i;
	t_stk	*tmp;

	i = 0;
	if (!stk)
		return ;
	while (i < count && stk)
	{
		tmp = stk;
		while (tmp->lek != ray->fakearray[i])
			tmp = tmp->next;
		tmp->realdex = i;
		i++;
	}
}

void	ft_freelst(t_stk *huaa)
{
	t_stk	*tmp;

	while (huaa != NULL)
	{
		tmp = huaa;
		huaa = huaa->next;
		free(tmp);
	}
}
