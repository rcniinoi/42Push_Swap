/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:35:46 by rchiewli          #+#    #+#             */
/*   Updated: 2022/11/01 23:25:43 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		wcount;
	t_array	ray;
	t_hua	*hua;

	ft_rayini(&ray);
	if (argc < 2)
		exit (0);
	wcount = ft_wordcountall(argc, argv);
	ray.charbuffer = ft_argumontobuffer(argc, argv, wcount);
	if (ft_errorchkall(wcount, &ray) == 0)
		ft_printerrorexit();
	ray.realarray = ft_atoisembe(ray.charbuffer, wcount);
	hua = malloc(sizeof(t_hua));
	ft_huaini(hua, &ray, wcount);
	ft_realindexini(hua->huaa, &ray, hua->aval);
	ft_swordpalanglumsang(hua, wcount, &ray);
	ft_freelst (hua->huaa);
	free (hua);
	free (ray.fakearray);
	free (ray.realarray);
	ft_freestrstr(ray.charbuffer);
}

void	ft_swordpalanglumsang(t_hua *hua, int wcount, t_array *ray)
{
	if (ft_chksworded(hua) != 1)
	{
		if (wcount == 2 && ft_chksworded(hua) == 0)
			ft_sa(hua, 1);
		else if (wcount == 3)
			ft_sortsammlast3(hua, wcount);
		else if (wcount <= 5)
			ft_indexsort(hua, ray, wcount);
		else if (wcount > 5)
		{
			ft_atob3(hua, wcount, (wcount / 100) + 3);
			ft_btoa3(hua, wcount);
		}
	}
}
