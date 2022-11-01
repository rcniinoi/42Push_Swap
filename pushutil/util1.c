/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:33:12 by rchiewli          #+#    #+#             */
/*   Updated: 2022/11/02 01:21:37 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_wordcountall(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1 && \
				ft_isdigit(argv[i][j + 1]) != 1)
				count++;
			else if ((ft_isdigit(argv[i][j]) != 1 && argv[i][j] != '-' && \
				argv[i][j] != '+' && argv[i][j] != ' ') || ((argv[i][j] == '-'\
				|| argv[i][j] == '+') && isdigit(argv[i][j + 1]) != 1))
				ft_printerrorexit();
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

char	**ft_argumontobuffer(int argc, char **argv, int count)
{
	int		i;
	int		j;
	int		k;
	char	**suffer;
	char	**splited;

	suffer = malloc((count + 1) * sizeof(char *));
	k = 0;
	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0')
			ft_freeprinterrorexit(suffer);
		splited = ft_split(argv[i], ' ');
		j = 0;
		while (splited[j])
		{
			suffer[k] = ft_strdup(splited[j]);
			k++;
			j++;
		}
		ft_freestrstr (splited);
	}
	return (suffer);
}

void	ft_printlst(t_stk *stk)
{
	if (stk == NULL)
		ft_dprintf(1, "-NULL-");
	while (stk != NULL)
	{
		ft_dprintf(1, "index = %d lek = %d realdex = %d\n" \
			, stk->index, stk->lek, stk->realdex);
		stk = stk->next;
	}
	ft_putendl_fd("", 1);
	stk = ft_lstfirst(stk);
}

void	ft_printintarray(int *array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_dprintf(1, "[%d] ", array[i]);
		i++;
	}
	ft_putendl_fd("", 1);
}

int	*ft_atoisembe(char **str, int count)
{
	int	i;
	int	*intsuffer;

	intsuffer = ft_calloc(count + 1, sizeof(int *));
	i = 0;
	while (i < count)
	{
		intsuffer[i] = ft_atoi(str[i]);
		i++;
	}
	return (intsuffer);
}
