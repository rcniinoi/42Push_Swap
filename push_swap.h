/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:01:37 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/13 18:23:24 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSHS_WAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "libftfinal/gnl5/get_next_line.h"
# include "dt_dpf/ft_printf.h"
# include <time.h>
# include "libftfinal/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stk
{
	int	lek;
	int	index;
	struct s_stk	*prev;
	struct s_stk	*next;
}	t_stk;

typedef struct s_hua
{
	struct s_stk	*huaa;
	struct s_stk	*huab;
	int	aval;
	int	bval;
}	t_hua;

typedef struct s_tmp
{
	struct s_stk	*tmp1;
	struct s_stk	*tmp2;
	struct s_stk	*tmp3;
	struct s_stk	*tmp4;
}	t_tmp;


#endif
