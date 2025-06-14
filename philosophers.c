/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:41 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/05/31 17:34:34 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_philo *philo = malloc(sizeof(t_philo));
	int	i = 0;
	if (ac <= 4 || ac > 6)
	{
		printf("Error in the Arguments");
		return (0);
	}
	while (i++ < ac - 1)
	{
		if (parsing_arguments(av[i]) == 1)
		{
			printf("Error in the Arguments");
			return (1);
		}
	}
		fill_the_struct(ac, av, philo);
		if (check_args(philo))
			return (1);
		printf("number of philo is : %d\n", philo->number_of_philosophers);
		printf("time to die is : %d\n", philo->time_to_die);
		printf("time to eat is : %d\n", philo->time_to_eat);
		printf("time to slepp is : %d\n", philo->time_to_sleep);
		printf("number_of_times_each_philosopher_must_eat is : %d\n", philo->number_of_times_each_philosopher_must_eat);
	return (0);
}
