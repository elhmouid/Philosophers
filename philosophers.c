/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:41 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/05/25 15:38:38 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	int	i = 0;
	if (ac <= 1)
		return (0);
	while (i++ < ac - 1)
	{
		if (parsing_arguments(av[i]) == 1)
		{
			printf("Error in the Arguments");
			return (1);
		}
		
	}
	return (0);
}