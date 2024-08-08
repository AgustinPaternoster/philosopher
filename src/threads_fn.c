#include "../inc/philo.h"

void pthreads_join(t_data * data)
{
    int i;

    i = 0;
    while(i < data->philo_nb)
    {
        pthread_join(data->philo[i].thread, NULL);
        i++;
    }
}

bool create_treads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_nb)
    {
        if (pthread_create(data->philo[i].thread,NULL,philo_rutine,(void*)data) != 0)
            return (FALSE);
    }
    
}