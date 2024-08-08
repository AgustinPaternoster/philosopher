#include "../inc/philo.h"
void star_thinking(t_philo *philo)
{
    ft_print_state(philo,THINK);
}
void star_sleepling(t_philo *philo)
{
    ft_print_state(philo,SLEEP);
    ft_usleep(philo->data->time_sleep);
}
void star_eating(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    ft_print_state(philo,FORK);
    pthread_mutex_lock(philo->left_fork);
    ft_print_state(philo,FORK);
    ft_print_state(philo,EAT);
    philo->last_meal = get_date_time();
    if (philo->meals >= 0)
        philo->meals++;
    ft_usleep(philo->data->time_eat);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}

void *philo_rutine(void *philos)
{
    t_philo *philo = (t_philo*)philos;
    if (philo->philo_id % 2 == 1)
        ft_usleep(philo->data->time_eat / 2);
    while(!philo->is_dead)
    {
        star_eating(philos);
        star_sleepling(philos);
        star_thinking(philos);
    }
	return (NULL);
}

