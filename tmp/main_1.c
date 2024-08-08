#include "../inc/philo.h"

pthread_mutex_t lock;

void philo_eat(t_philo * philo)
{
	printf("%ld %d is eating\n",get_date_time(),philo->philo_id);
	ft_usleep(philo->time_eat);
	philo->last_meal = get_date_time();
	philo->meals_nb++;
}

void philo_sleep(t_philo * philo)
{
	//printf("%ld %d is sleeping\n",get_date_time(),philo->philo_id);
	ft_usleep(philo->time_sleep);
}

void philo_think(t_philo * philo)
{
	//printf("%ld %d is thinking\n",get_date_time(),philo->philo_id);
	ft_usleep(philo->time_sleep);
}



void *philo_routine(void * philosopher)
{
	t_philo *philo;
	philo = (t_philo *)philosopher;
	while(!philo->is_dead) 
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void * monitor_routine(void * philosophers)
{ 
	int i;
	t_philo *philo;
	size_t time;

	printf("monitor starting\n");
	philo = (t_philo *)philosophers;
	while(1)
	{
		i = 0;
		while (i < philo[0].philo_nb)
		{
			time = get_date_time() - philo[i].last_meal;
			//printf("time: %ld\n", time);
			if (time > (size_t)philo[i].time_die)
			{	
				philo[i].is_dead = 1;
				printf("philo: %d is dead\n time: %ld", philo[i].philo_id,time);
				exit(0);
			}
			i++;
		}
			
	}
}

void start_philo(char **argv, t_philo *philo, int i)
{
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->philo_id = i+1;
	philo->is_dead = 0;
	philo->last_meal = get_date_time();
	philo->philo_nb = ft_atoi(argv[1]);
}

int main(int arc, char **argv)
{
	
	t_philo		philo[ft_atoi(argv[1]) + 1];
	t_fork		forks[ft_atoi(argv[1])];
	int i;

	(void)arc;
	(void)forks;
	i = 0;
	while(i < ft_atoi(argv[1]))
	{
		start_philo(argv,&philo[i],i);
		if(pthread_create(&philo[i].thread ,NULL,philo_routine,&philo[i]) == -1)
			return(ft_putstr_fd(ERROR_2,2),1);
		i++;
	}
	if(pthread_create(&philo[i + 1].thread ,NULL,monitor_routine,&philo) == -1)
		return(ft_putstr_fd(ERROR_2,2),1);
	i = 0;
	while(i < ft_atoi(argv[1]))
	{
		pthread_join(philo[i].thread,NULL);
		i++;
	}
	//pthread_mutex_destroy(&lock);
	//printf("ejecucion terminada");
	return (0);
}