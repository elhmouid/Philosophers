#ifndef PHILO
# define PHILO

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>


typedef struct s_philosophers {
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
}   t_philo;

int	parsing_arguments(char *av);
int	ft_atoi(char *str);
void	fill_the_struct(int ac, char **av, t_philo *philo);
int check_args(t_philo *philo);

#endif