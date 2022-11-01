/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:17:15 by rchiewli          #+#    #+#             */
/*   Updated: 2022/11/01 23:34:52 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	rst;
	int		sign;

	sign = 1;
	rst = 0;
	i = 0;
	while ((str[i] && (str[i] >= '\t' && str[i] <= '\r')) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if ((str[i] == '-' || str[i] == '+') && (!ft_isdigit(str[i + 1]) || !str[i + 1]))
			ft_printerrorexit();
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		rst *= 10;
		rst += (str[i] - '0');
		i++;
	}
	if (rst * sign < INT_MIN || rst * sign > INT_MAX || str[i])
		ft_printerrorexit();
	return (rst * sign);
}

/*int main()
{
	int ato = ft_atoi("475");
	printf ("%d\n",ato);
	int aoo = atoi("475");
	printf ("%d\n",aoo);
}*/
