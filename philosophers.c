/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:41 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/05/23 17:16:48 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	int	i = 0;
	if (ac <= 1)
		return (0);
	while (i++ < ac)
		parsing_arguments(av[i]);
	return (0);
}