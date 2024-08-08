#include "../inc/philo.h"
bool check_nb(int arc, char **argv)
{
	int i;
	int j;
	long nb;

	i = 1;
	while(i < arc)
	{
		j = 0;
		nb = atol(argv[i]);
		while (argv[i][j])
		{
			if (!ft_isnumber(argv[i][j]))
				return (FALSE);
			j++;
		}
		if (nb < 0)
			return (FALSE);
		if (nb < INT_MIN || nb > INT_MAX)
			return (FALSE);
	i++;
	}
	return (TRUE);

}

bool check_arguments(int arg, char **argv )
{
	if (arg < 4 || arg > 5)
		return (FALSE);
	if (!check_nb(arg,argv))
		return (FALSE);
	if (atol(argv[1]) < 2)
		return (FALSE);

	return (TRUE);
}



int main(int arc, char **argv)
{
	
	t_philo				philo[ft_atol(argv[1])];
	t_data 				data;
	pthread_mutex_t		forks[ft_atol(argv[1])];
	pthread_t			monitor;
	
	(void)monitor;
	if (!check_arguments(arc, argv))
		return (printf(RULES),1);
	if(!init_data(&data, philo,argv,arc))
		return (printf(ERROR_3),1);
	if(!create_forks(forks,data.philo_nb))
		return (printf(ERROR_3),1);
	init_philo(&data, forks);
	pthreads_join(&data);
	destroy_mutex(&data);

	

	return (0);
}