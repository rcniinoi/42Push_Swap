/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhand1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:34:45 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 16:34:46 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_printerrorexit(void)
{
	ft_dprintf(2, "Error\n");
	exit (0);
}

void	ft_freestrstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
}

int	ft_errchk(char **str, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (count == 0)
		return (0);
	while (i < count)
	{
		while (ft_isdigit(str[i][j]) == 1 || str[i][j] == '-')
		{
			if (str[i][j] == '-' && str[i][j + 1] == '-')
				return (0);
			if (str[i][j + 1] && ft_isdigit(str[i][j + 1]) != 1)
				return (0);
			if (str[i][j] == '-' && (ft_isdigit(str[i][j + 1]) \
				!= 1 || !str[i][j + 1]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_chkintdup(int *array, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (array[i] == array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_errorchkall(int wcount, t_array *ray)
{
	if (wcount == 0)
		exit (0);
	if (ft_errchk(ray->charbuffer, wcount) == 0)
		return (0);
	ray->fakearray = ft_atoisembe(ray->charbuffer, wcount);
	ray->fakearray = ft_quick(ray->fakearray, 0, wcount);
	if (ft_chkintdup(ray->fakearray, wcount) == 0)
		return (0);
	return (1);
}
