/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:47:19 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/07 15:28:19 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_threads_even(t_philosopher *tab_philo, t_table *table)
{
	unsigned int	i;

	i = 1;
	while (i < table->n)
	{
		if (pthread_create(
				&((tab_philo[i]).thread), NULL, routine_even, &(tab_philo[i])))
			return (0);
		i += 2;
	}
	usleep(table->t_eat * 1000);
	i = 0;
	while (i < (table->n - 2))
	{
		if (pthread_create(
				&((tab_philo[i]).thread), NULL, routine_even, &(tab_philo[i])))
			return (0);
		i += 2;
	}
	pthread_create(&((tab_philo[i]).thread),
		NULL, routine_even_last, &(tab_philo[table->n - 2]));
	pthread_create(&(table->thread_stop), NULL, stop, tab_philo);
	return (1);
}

static int	start_threads_odd(t_philosopher *tab_philo, t_table *table)
{
	unsigned int	i;

	i = 1;
	while (i < table->n)
	{
		if (pthread_create(
				&((tab_philo[i]).thread), NULL, routine_odd, &(tab_philo[i])))
			return (0);
		i += 2;
	}
	usleep(table->t_eat * 500);
	i = 0;
	while (i < (table->n - 1))
	{
		if (pthread_create(
				&((tab_philo[i]).thread), NULL, routine_odd, &(tab_philo[i])))
			return (0);
		i += 2;
	}
	usleep(table->t_eat * 1000);
	pthread_create(&((tab_philo[i]).thread),
		NULL, routine_odd_last, &(tab_philo[table->n - 1]));
	pthread_create(&(table->thread_stop), NULL, stop, tab_philo);
	return (1);
}

int	start_threads(t_philosopher *tab_philo, t_table *table)
{
	if (table->n == 1)
	{
		pthread_create(
			&((tab_philo[0]).thread), NULL, routine_one, &(tab_philo[0]));
		pthread_create(&(table->thread_stop), NULL, stop, tab_philo);
		return (1);
	}
	else if (table->n % 2 == 1)
		return (start_threads_odd(tab_philo, table));
	else
		return (start_threads_even(tab_philo, table));
}

int	wait_threads(t_table *table)
{
	if (pthread_join(table->thread_stop, NULL))
		return (0);
	return (1);
}
