#include "../inc/philo.h"

long	ft_atol(const char *nptr)
{
	int	i;

	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * neg);
}


long get_date_time()
{
	struct timeval time;

	if (gettimeofday(&time,NULL) != 0)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void ft_usleep(int miliseconds)
{
	long init;
	long mils;

	mils = 0;
	init = get_date_time();
	while ( mils < miliseconds)
	{
    	usleep (500);
    	mils = (get_date_time() - init);
	}
}

bool ft_isnumber(char c)
{
	if (c < 48 || c > 57)
		return (FALSE);
	return (TRUE);
}


