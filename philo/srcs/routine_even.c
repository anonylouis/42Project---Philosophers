/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_even.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:18:33 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:39:33 by lcalvie          ###   ########.fr       */
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

void	*routine_even(void *void_philo)
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
		usleep((philo->table)->t_sleep * 1000);
		print_status(philo->table, 3, time_lld(philo->table), philo->nb + 1);
		finished = can_talk(philo);
	}
	return (NULL);
}

void	*routine_even_last(void *void_philo)
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
		usleep((philo->table)->t_sleep * 1000);
		print_status(philo->table, 3, time_lld(philo->table), philo->nb + 1);
		finished = can_talk(philo);
	}
	return (NULL);
}
