/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <buthor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:55:23 by buthor            #+#    #+#             */
/*   Updated: 2021/09/22 16:05:59 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	number_of_word;
	int	number_of_letter;

	number_of_word = 0;
	if (ac != 6 && ac != 5)
		return (FALSE);
	while (++number_of_word != ac)
	{
		number_of_letter = 0;
		if (av[number_of_word][number_of_letter] == '0')
			return (FALSE);
		while (av[number_of_word][number_of_letter] != END_OF_STRING)
		{
			if (ft_isdigit(av[number_of_word][number_of_letter]) == FALSE)
				return (FALSE);
			number_of_letter++;
		}
	}
	return (TRUE);
}

int	check_death(t_data *data, long long start_time, int index, int qty_ate_idx)
{
	while (index != data->args.qty_of_philos)
	{
		if (data->philo[index].time_before_eat > 0)
		{
			if (data->philo[index].time_to_die <= get_time()
				- data->philo[index].time_before_eat)
			{
				pthread_mutex_lock(&(data->printf));
				printf(DEATH, data->philo[index].id, get_time() - start_time);
				return (TRUE);
			}
			if (data->philo[index].number_of_eat == ATE)
				qty_ate_idx++;
		}
		if (qty_ate_idx == data->args.qty_of_philos)
		{
			pthread_mutex_lock(&(data->printf));
			printf("Philosophers are full of %lld ms!\n", get_time()
				- start_time);
			return (TRUE);
		}
		index++;
	}
	return (FALSE);
}
