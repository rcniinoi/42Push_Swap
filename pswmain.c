#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	wcount;
	t_array	*ray;
	t_hua	*hua;

	ray = malloc(sizeof(t_array));
	if (argc < 2)
		exit (0);
	wcount = ft_wordcountall(argc, argv);
	ray->charbuffer = ft_argumontobuffer(argc,argv, wcount);
	if (ft_errorchkall(wcount, ray) == 0)
		ft_printerrorexit();
	ray->realarray = ft_atoisembe(ray->charbuffer, wcount);
	hua = malloc(sizeof(t_hua));
	hua->aval = wcount;
	hua->bval = 0;
	hua->huaa = ft_stkabini(ray->realarray, wcount);


	ft_rr(hua);
	ft_printlst(hua->huaa);
	ft_printlst(hua->huab);
	// free (hua);
	// ft_freestrstr(ray->charbuffer);
	// free (ray);
}
