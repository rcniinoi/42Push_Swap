/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:01:37 by rchiewli          #+#    #+#             */
/*   Updated: 2022/11/02 00:28:35 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
# include "dt_dpf/ft_printf.h"
# include <time.h>
# include "libftfinal/libft.h"
# include "gnlpush/get_next_line.h"

typedef struct s_stk
{
	int				lek;
	int				index;
	int				realdex;
	struct s_stk	*prev;
	struct s_stk	*next;
}	t_stk;

typedef struct s_hua
{
	struct s_stk	*huaa;
	struct s_stk	*huab;
	int				aval;
	int				bval;
}	t_hua;

typedef struct s_tmp
{
	struct s_stk	*tmp1;
	struct s_stk	*tmp2;
	struct s_stk	*tmp3;
	struct s_stk	*tmp4;
}	t_tmp;

typedef struct s_array
{
	int		*realarray;
	int		*fakearray;
	char	**charbuffer;

}	t_array;

int		ft_printerrorexit(void);
int		ft_wordcountall(int argc, char **argv);
void	ft_printintarray(int *array, int count);
void	ft_freestrstr(char **str);
void	ft_printlst(t_stk *stk);
int		*ft_quick(int *array, int low, int high);
char	**ft_argumontobuffer(int argc, char **argv, int count);
int		*ft_atoisembe(char **str, int count);
int		ft_errchk(char **str, int count);
int		ft_chkintdup(int *array, int count);
int		ft_errorchkall(int wcount, t_array	*ray);
t_stk	*ft_lstlast2(t_stk *lst);
t_stk	*ft_lstfirst(t_stk *lst);
t_stk	*ft_lstaddklang(t_stk *front, t_stk *back);
void	ft_t_stkini(t_stk *wen);
void	ft_huastarter(t_hua *hua, int count);
t_stk	*ft_stkabini(int *sembe, int count);
void	ft_swap(t_stk	*huax);
void	ft_swapab(int *a, int *b);
void	ft_sa(t_hua *hua, int mode);
void	ft_sb(t_hua *hua, int mode);
void	ft_ss(t_hua	*hua, int mode);
void	ft_rotate(t_stk *huax, t_stk *end);
void	ft_ra(t_hua *hua, int count, int mode);
void	ft_rb(t_hua *hua, int count, int mode);
void	ft_rr(t_hua	*hua, int mode);
void	ft_tmpstarter(t_tmp *tmp);
void	ft_push(t_hua *hua, t_stk *huafrom, t_stk *huato, int mode);
void	ft_pa(t_hua	*hua, int mode);
void	ft_pb(t_hua	*hua, int mode);
void	ft_rerotate(t_stk *huax, t_stk *end);
void	ft_rra(t_hua *hua, int count, int mode);
void	ft_rrb(t_hua *hua, int count, int mode);
void	ft_rrr(t_hua *hua, int mode);
void	ft_indexsort(t_hua *hua, t_array *ray, int count);
void	ft_indexkayap_pa(t_hua *hua, int i, int j, int mode);
void	ft_indexkayap_pb(t_hua *hua, int i, int j, int mode);
void	ft_sortsamm(t_hua *hua, t_array *ray);
void	ft_sortsammlast(t_hua *hua, t_array *ray, int count);
int		ft_chksworded(t_hua *hua);
void	ft_huaini(t_hua *hua, t_array *ray, int count);
void	ft_rayini(t_array *ray);
void	ft_sortsammany(t_hua *hua, t_array *ray, int count);
void	ft_atob(t_hua *hua, t_array *ray, int count, int times);
void	ft_btoa(t_hua *hua, t_array *ray, int count);
void	ft_realindexini(t_stk *stk, t_array *ray, int count);
void	ft_atob3(t_hua *hua, int count, int times);
void	ft_sortsammlast3(t_hua *hua, int count);
void	ft_btoa3(t_hua *hua, int count);
int		ft_lekrieng(t_hua *hua);
void	ft_freelst(t_stk *huaa);
void	ft_swordpalanglumsang(t_hua *hua, int wcount, t_array *ray);
void	ft_sortbonorlang(t_hua *hua, t_array *ray, int i, int mode);
void	ft_sbpa(t_hua *hua);
void	ft_rrbpa(t_hua *hua);
int		ft_doreturnyone(t_hua *hua, int yone, int mode);
void	ft_tmpfindmove(t_hua *hua, t_stk *tmpfind, int now);
void	ft_movepaornot(t_hua *hua, int now, t_stk *tmpfind, t_stk *tmpb);
int		ft_gaeconditionnorm(int yone, t_hua *hua, int now);
int		ft_chkstart(int argc, char **argv, t_hua *hua, int wcount);
void	ft_chkchk(t_hua *hua, char *buffer);
void	ft_okko(t_hua *hua, int wcount);
int		ft_freeprinterrorexit(char **str);

#endif
