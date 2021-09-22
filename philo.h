/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <buthor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:55:22 by buthor            #+#    #+#             */
/*   Updated: 2021/09/22 15:53:24 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define GET_LEFT_FORK "Philosopher %i took the left fork at %lld ms\n"
# define GET_RIGHT_FORK "Philosopher %i took the right fork at %lld ms\n"
# define GO_SLEEP "Philosopher %i sleeps at %lld ms\n"
# define START_EAT "Philosopher %i eats %lld ms\n"
# define START_THINK "Philosopher %i thinks at %lld ms\n"
# define DEATH "Philosopher %d died at %lld ms!\n"
# define TRUE 0
# define FALSE -1
# define ATE 0
# define END_OF_STRING '\0'
# define WRONG_ARGS "Wrong arguments: number_of_philosophers, time_to_die, \
time_to_eat, time_to_sleep, or number_of_times_each_philosopher_must_eat \
must be a positive number!"

typedef struct s_args
{
	int	qty_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_eat;
}				t_args;

typedef struct s_philosophers
{
	pthread_t		tread;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		time_before_eat;
	int				number_of_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*printf;
	int				id;
	long long		time_of_start_simulation;
}				t_philosophers;

typedef struct s_data
{
	t_args			args;
	t_philosophers	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf;
}				t_data;

int			check_args(int ac, char **av);
int			ft_isdigit(int c);
int			print_and_return(char *text_error);
int			init_data(int ac, char **av, t_data *data);
void		init_args(int ac, char **av, t_data *data);
int			str_to_digit(const char *s);
int			init_mass_struct_philosophers_and_forks(t_data *data);
long long	get_time(void);
void		start_of_simulation(t_data *data, long long start_time);
void		*life_of_philo(void *data);
void		printf_whith_mutex(char *text, t_philosophers *philo);
void		stopwatch(long time);
int			check_death(t_data *data, long long start_time, int index,
				int qty_ate_idx);
#endif
