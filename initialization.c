/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <buthor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:45:56 by buthor            #+#    #+#             */
/*   Updated: 2021/09/22 16:06:18 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int ac, char **av, t_data *data)
{
	init_args(ac, av, data);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->args.qty_of_philos);
	if (data->forks == NULL)
		return (FALSE);
	data->philo = malloc(sizeof(t_philosophers)
			* data->args.qty_of_philos);
	if (data->philo == NULL)
		return (FALSE);
	if (pthread_mutex_init(&data->printf, NULL) != TRUE)
		return (print_and_return("Can't init printf mutex!\n"));
	if (init_mass_struct_philosophers_and_forks(data) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	init_args(int ac, char **av, t_data *data)
{
	int	number_of_word;

	number_of_word = 0;
	data->args.qty_of_philos = str_to_digit(av[++number_of_word]);
	data->args.time_to_die = str_to_digit(av[++number_of_word]);
	data->args.time_to_eat = str_to_digit(av[++number_of_word]);
	data->args.time_to_sleep = str_to_digit(av[++number_of_word]);
	if (ac == 5)
		data->args.number_of_eat = FALSE;
	else
		data->args.number_of_eat = str_to_digit(av[++number_of_word]);
}

int	init_mass_struct_philosophers_and_forks(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->args.qty_of_philos)
	{
		data->philo[index].time_to_sleep = data->args.time_to_sleep;
		data->philo[index].time_to_eat = data->args.time_to_eat;
		data->philo[index].time_to_die = data->args.time_to_die;
		data->philo[index].number_of_eat = data->args.number_of_eat;
		data->philo[index].time_before_eat = 0;
		data->philo[index].id = index;
		data->philo[index].printf = &data->printf;
		if (pthread_mutex_init(&data->forks[index], NULL) != TRUE)
			return (print_and_return("Can't init forks mutex!\n"));
		data->philo[index].left = &data->forks[index];
		data->philo[index].right = &data->forks[(index + 1)
			% data->args.qty_of_philos];
		data->philo[index].time_of_start_simulation = 0;
		index++;
	}
	return (TRUE);
}
