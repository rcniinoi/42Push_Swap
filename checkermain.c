/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:22:49 by rchiewli          #+#    #+#             */
/*   Updated: 2022/11/01 22:57:16 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		wcount;
	char	*buffer;
	t_hua	*hua;
	t_array	ray;

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
	buffer = get_next_line(0);
	while (buffer)
	{
		ft_chkchk(hua, buffer);
		free(buffer);
		buffer = get_next_line(0);
	}
	ft_okko(hua, wcount);
}

void	ft_chkchk(t_hua *hua, char *buffer)
{
	if (ft_strncmp(buffer, "sa\n", 3) == 0)
		ft_sa(hua, 2);
	else if (ft_strncmp(buffer, "sb\n", 3) == 0)
		ft_sb(hua, 2);
	else if (ft_strncmp(buffer, "ss\n", 3) == 0)
		ft_ss(hua, 2);
	else if (ft_strncmp(buffer, "ra\n", 3) == 0)
		ft_ra(hua, hua->aval, 2);
	else if (ft_strncmp(buffer, "rb\n", 3) == 0)
		ft_rb(hua, hua->bval, 2);
	else if (ft_strncmp(buffer, "rr\n", 3) == 0)
		ft_rr(hua, 2);
	else if (ft_strncmp(buffer, "rra\n", 4) == 0)
		ft_rra(hua, hua->aval, 2);
	else if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		ft_rrb(hua, hua->bval, 2);
	else if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		ft_rrr(hua, 2);
	else if (ft_strncmp(buffer, "pa\n", 3) == 0)
		ft_pa(hua, 2);
	else if (ft_strncmp(buffer, "pb\n", 3) == 0)
		ft_pb(hua, 2);
	else
		ft_printerrorexit();
}

void	ft_okko(t_hua *hua, int wcount)
{
	if (ft_chksworded(hua) == 1 && hua->aval == wcount && hua->bval == 0)
		ft_dprintf(1, "OK\n");
	else if (ft_chksworded(hua) != 1)
		ft_dprintf(1, "KO\n");
}
