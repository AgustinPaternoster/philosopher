#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
#include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

//Estates
# define SLEEP "is sleeping"
# define FORK "has taken a fork"
# define THINK "is thinking"
# define EAT "is eating"
//Errors
# define ERROR_1 "Time fuction failed\n"
# define ERROR_2 "Pthread create failed\n"
# define ERROR_3 "Mutex create failed\n"
#define RULES \
    "Error\n" \
    "1. The number of arguments must be 4 or 5.\n" \
    "2. Only positive integers are allowed.\n" \
    "3. The number of philosophers must be greater than 1.\n"

typedef enum
{
	FALSE,
	TRUE
}bool;

typedef struct  c_philo
{
	pthread_t thread;
    int philo_id;
    int meals;
    int is_dead;
    size_t last_meal;
    size_t start_time;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    struct s_data *data; 
}t_philo;

typedef struct s_data
{
    t_philo *philo;
    long philo_nb;
    long time_eat;
    long time_sleep;
    long time_die;
    int meals_nb;
    bool all_philo_ready;
    pthread_mutex_t write;
    pthread_mutex_t read;
    pthread_mutex_t set;
    pthread_t monitor;
}t_data;

//utilities
long get_date_time();
void ft_usleep(int miliseconds);
//libft
long	ft_atol(const char *nptr);
bool ft_isnumber(char c);
//init
bool init_data(t_data *data, t_philo *philos, char **argv, long arc);
bool create_forks(pthread_mutex_t *forks, long forks_nb);
void init_philo(t_data *data, pthread_mutex_t *forks);
//philo
void *philo_rutine(void *data);
//threads
void pthreads_join(t_data * data);
//mutex
void ft_print_state(t_philo *philo,char *state);
void destroy_mutex(t_data *data);


#endif