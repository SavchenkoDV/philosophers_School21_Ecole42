/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <buthor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:54:04 by buthor            #+#    #+#             */
/*   Updated: 2021/09/22 15:53:24 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	str_to_digit(const char *s)
{
	int		i;
	int		nb;
	char	*str;

	str = (char *)s;
	i = 0;
	nb = str[i] - '0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] && ((i == 9 && str[i] >= '7') || i == 10))
			return (2147483647);
		else if (str[i + 1] && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			nb = nb * 10 + (str[i + 1] - '0');
		else
			return (nb);
		i++;
	}
	return (0);
}

int	print_and_return(char *text_error)
{
	printf ("%s\n", text_error);
	return (FALSE);
}

void	printf_whith_mutex(char *text, t_philosophers *philo)
{
	pthread_mutex_lock(philo->printf);
	printf(text, philo->id, get_time() - philo->time_of_start_simulation);
	pthread_mutex_unlock(philo->printf);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
