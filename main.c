/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <buthor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:20:56 by buthor            #+#    #+#             */
/*   Updated: 2021/09/22 16:45:04 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_of_simulation(t_data *data, long long start_time)
{
	int	index;

	index = 0;
	while (index < data->args.qty_of_philos)
	{
		if (index % 2 == 0)
		{
			data->philo[index].time_of_start_simulation = start_time;
			pthread_create(&data->philo[index].tread, NULL, life_of_philo,
				(void *)(&data->philo[index]));
		}
		index++;
	}
	usleep(data->args.qty_of_philos * 15);
	index = 1;
	while (index < data->args.qty_of_philos)
	{
		if (index % 2 != 0)
		{
			data->philo[index].time_of_start_simulation = start_time;
			pthread_create(&data->philo[index].tread, NULL, life_of_philo,
				(void *)(&data->philo[index]));
		}
		index++;
	}
}

void	*life_of_philo(void *data)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)data;
	while (1)
	{
		pthread_mutex_lock(philo->left);
		printf_whith_mutex(GET_LEFT_FORK, philo);
		pthread_mutex_lock(philo->right);
		printf_whith_mutex(GET_RIGHT_FORK, philo);
		philo->time_before_eat = get_time();
		printf_whith_mutex(START_EAT, philo);
		stopwatch(philo->time_to_eat);
		if (philo->number_of_eat > 0)
			philo->number_of_eat--;
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		printf_whith_mutex(GO_SLEEP, philo);
		stopwatch(philo->time_to_sleep);
		printf_whith_mutex(START_THINK, philo);
	}
}

void	stopwatch(long time)
{
	long	stop_eating;

	stop_eating = get_time() + time;
	while (stop_eating > get_time())
		usleep(1);
}

int	main(int argc, char **argv)
{
	t_data		data;
	int			end_of_simulation;
	long long	start_time;

	end_of_simulation = FALSE;
	if (check_args(argc, argv) == FALSE)
		return (print_and_return(WRONG_ARGS));
	if (init_data(argc, argv, &data) == FALSE)
		return (print_and_return("Can't init_data\n"));
	start_time = get_time();
	if (data.args.qty_of_philos == 1)
	{
		printf(GET_LEFT_FORK, 0, (long long)0);
		usleep(data.args.time_to_die * 1000);
		printf(DEATH, 0, (long long)data.args.time_to_die);
	}
	else
		start_of_simulation(&data, start_time);
	while (end_of_simulation == FALSE && data.args.qty_of_philos > 1)
		end_of_simulation = check_death(&data, start_time, 0, 0);
	free(data.forks);
	free(data.philo);
	return (TRUE);
}
