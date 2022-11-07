/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:36:21 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:40:07 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	is_someone_dead(t_philosopher *tab_philo, t_table *ptr_table)
{
	unsigned int	i;
	long long		t;
	long long		last_meal;

	i = 0;
	while (i < ptr_table->n)
	{
		pthread_mutex_lock(&((tab_philo[i]).mtx_last_meal));
		last_meal = (tab_philo)[i].last_meal;
		pthread_mutex_unlock(&((tab_philo[i]).mtx_last_meal));
		t = time_lld(ptr_table);
		if ((t - last_meal) >= (long long) ptr_table->t_death)
		{
			pthread_mutex_lock(&(ptr_table->mtx_talk));
			ptr_table->can_talk = 0;
			pthread_mutex_unlock(&(ptr_table->mtx_talk));
			printf("%lld %u died\n", t, i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	finished(t_table *ptr_table)
{
	unsigned int	number_meal;

	pthread_mutex_lock(&(ptr_table->mtx_number_meal));
	number_meal = ptr_table->number_meal;
	pthread_mutex_unlock(&(ptr_table->mtx_number_meal));
	if (number_meal >= ptr_table->n_to_eat)
	{
		pthread_mutex_lock(&(ptr_table->mtx_talk));
		ptr_table->can_talk = 0;
		pthread_mutex_unlock(&(ptr_table->mtx_talk));
		return (1);
	}
	else
		return (0);
}

static void	*stop_death(t_philosopher *tab_philo, t_table *ptr_table)
{
	unsigned int	i;

	while (!is_someone_dead(tab_philo, ptr_table))
	{
	}
	usleep(1600 * ptr_table->t_eat);
	i = 0;
	while (i < ptr_table->n)
	{
		if (pthread_join((tab_philo[i]).thread, NULL))
			return (0);
		i++;
	}
	return (NULL);
}

static void	*stop_meal(t_philosopher *tab_philo, t_table *ptr_table)
{
	unsigned int	i;

	while (!is_someone_dead(tab_philo, ptr_table) && !finished(ptr_table))
	{
	}
	usleep(1600 * ptr_table->t_eat);
	i = 0;
	while (i < ptr_table->n)
	{
		if (pthread_join((tab_philo[i]).thread, NULL))
			return (0);
		i++;
	}
	return (NULL);
}

void	*stop(void *void_tab_philo)
{
	t_philosopher	*tab_philo;
	t_table			*ptr_table;

	tab_philo = (t_philosopher *) void_tab_philo;
	ptr_table = ((tab_philo)[0]).table;
	if (ptr_table->argc == 5)
		return (stop_death(tab_philo, ptr_table));
	else
		return (stop_meal(tab_philo, ptr_table));
}
