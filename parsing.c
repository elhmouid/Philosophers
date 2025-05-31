/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:06:09 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/05/31 17:33:31 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <linux/limits.h>

int ft_atoi(char *str)
{
    long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str[i])
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	parsing_arguments(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (1);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

void	fill_the_struct(int ac, char **av, t_philo *philo)
{
		philo->number_of_philosophers = ft_atoi(av[1]);
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_eat = ft_atoi(av[3]);
		philo->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		else 
			philo->number_of_times_each_philosopher_must_eat = -1;
}
int check_args(t_philo *philo)
{
	if (philo->number_of_philosophers == 0
    || philo->time_to_die == 0
    || philo->time_to_eat == 0
    || philo->time_to_sleep == 0
	|| philo->number_of_times_each_philosopher_must_eat == 0)
	{
    	printf("Error: Arguments must be greater than zero.\n");
    	return (1);
	}
	return (0);
}