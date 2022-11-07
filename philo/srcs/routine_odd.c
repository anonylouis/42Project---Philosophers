/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_odd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:53:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:39:27 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	can_talk(t_philosopher *philo)
{
	int	finished;

	pthread_mutex_lock(&((philo->table)->mtx_talk));
	finished = (philo->table)->can_talk;
	pthread_mutex_unlock(&((philo->table)->mtx_talk));
	return (finished);
}

static	void	new_tempo(t_philosopher *philo)
{
	if (philo->tempo >= (((philo->table)->n) / 2))
	{
		philo->tempo = 0;
		usleep((philo->table)->t_eat * 1000);
	}
}

void	*routine_odd(void *void_philo)
{
	t_philosopher	*philo;
	int				finished;

	philo = (t_philosopher *) void_philo;
	finished = can_talk(philo);
	while (finished)
	{
		lock_forks(philo);
		pthread_mutex_lock(&(philo->mtx_last_meal));
		philo->last_meal = time_lld(philo->table);
		print_status(philo->table, 1, philo->last_meal, philo->nb + 1);
		pthread_mutex_unlock(&(philo->mtx_last_meal));
		usleep((philo->table)->t_eat * 1000);
		unlock_forks(philo);
		print_status(philo->table, 2, time_lld(philo->table), philo->nb + 1);
		(philo->tempo)++;
		usleep((philo->table)->t_sleep * 1000);
		print_status(philo->table, 3, time_lld(philo->table), philo->nb + 1);
		new_tempo(philo);
		finished = can_talk(philo);
	}
	return (NULL);
}

void	*routine_odd_last(void *void_philo)
{
	t_philosopher	*philo;
	int				finished;

	philo = (t_philosopher *) void_philo;
	finished = can_talk(philo);
	while (finished)
	{
		lock_forks(philo);
		pthread_mutex_lock(&(philo->mtx_last_meal));
		philo->last_meal = time_lld(philo->table);
		print_status(philo->table, 1, philo->last_meal, philo->nb + 1);
		pthread_mutex_unlock(&(philo->mtx_last_meal));
		usleep((philo->table)->t_eat * 1000);
		unlock_forks(philo);
		print_status(philo->table, 2, time_lld(philo->table), philo->nb + 1);
		pthread_mutex_lock(&((philo->table)->mtx_number_meal));
		((philo->table)->number_meal)++;
		pthread_mutex_unlock(&((philo->table)->mtx_number_meal));
		(philo->tempo)++;
		usleep((philo->table)->t_sleep * 1000);
		print_status(philo->table, 3, time_lld(philo->table), philo->nb + 1);
		new_tempo(philo);
		finished = can_talk(philo);
	}
	return (NULL);
}

void	*routine_one(void *void_philo)
{
	t_philosopher	*philo;
	int				finished;

	philo = (t_philosopher *) void_philo;
	pthread_mutex_lock(&(((philo->table)->forks)[0]));
	print_status(philo->table, 0, time_lld(philo->table), 1);
	finished = can_talk(philo);
	while (finished)
		finished = can_talk(philo);
	pthread_mutex_unlock(&(((philo->table)->forks)[0]));
	return (NULL);
}
