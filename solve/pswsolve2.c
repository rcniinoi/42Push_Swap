/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswsolve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:29:18 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 16:30:03 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrbpa(t_hua *hua)
{
	ft_rrb(hua, hua->bval, 1);
	ft_pa(hua, 1);
}
