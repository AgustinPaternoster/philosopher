#include "../inc/philo.h"

bool init_data(t_data *data, t_philo *philos, char **argv, long arc)
{
	data->philo = philos;
	(void)philos;
	data->philo_nb = ft_atol(argv[1]);
	data->time_die = ft_atol(argv[2]);
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	data->all_philo_ready = FALSE;
	if (arc == 5)
		data->meals_nb = -1;
	else
		data->meals_nb = ft_atol(argv[6]);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&data->read, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&data->set, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

bool create_forks(pthread_mutex_t *forks, long forks_nb)
{
	int i;

	i = 0;
	while(i < forks_nb)
	{
		if(pthread_mutex_init(&forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void init_philo(t_data *data, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while(i < data->philo_nb)
	{	
		data->philo[i].philo_id = i + 1;
		data->philo[i].is_dead = 0;
		data->philo[i].meals = 0;
		data->philo[i].start_time = get_date_time();
		data->philo[i].data = data;
		data->philo[i].right_fork = &forks[i];
		data->philo[i].left_fork = &forks[(i + 1) % data->philo_nb];
		i++;
	}
}