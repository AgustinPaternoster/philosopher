#include "../inc/philo.h"

void ft_print_state(t_philo *philo,char *state)
{
    ssize_t time;
    pthread_mutex_lock(&philo->data->write);
    time = get_date_time() - philo->start_time;
    printf("%ld %d %s\n",time,philo->philo_id, state);
    pthread_mutex_unlock(&philo->data->write);
}

void destroy_mutex(t_data *data)
{
    int i;

    i = 0;
    while(i < data->philo_nb)
    {
        pthread_mutex_destroy(data->philo[i].right_fork);
        pthread_mutex_destroy(data->philo[i].left_fork);
    }
    pthread_mutex_destroy(&data->write);
}

bool get_safe_bool(pthread_mutex_t *mutex, bool *bool)
{
    pthread_mutex_lock(mutex);
    bool = *bool;
    pthread_mutex_unlock(mutex);
    return (bool);
}

void set_safe_bool(pthread_mutex_t *mutex, bool *var,bool value)
{
    pthread_mutex_look(mutex);
    *var = value;
    pthread_mutex_unlook(mutex);
}

