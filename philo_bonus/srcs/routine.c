/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 06:49:42 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:14:06 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	*routine_sem_death(void *void_philo)
{
	t_philosopher	*philo;
	t_table			*ptr_table;
	long long		last_meal;
	long long		t;

	philo = (t_philosopher *) void_philo;
	ptr_table = philo->table;
	while (1)
	{
		sem_wait(philo->sem_last_meal);
		last_meal = philo->last_meal;
		sem_post(philo->sem_last_meal);
		t = time_lld(ptr_table);
		if ((t - last_meal) >= (long long) ptr_table->t_death)
		{
			sem_post(ptr_table->sem_death);
			sem_wait(ptr_table->sem_death_msg);
			printf("%lld %u died\n", t, philo->nb + 1);
			return (NULL);
		}
		usleep(1);
	}
}

static	void	new_tempo(t_philosopher *philo, t_table *table)
{
	if ((table->n % 2) == 1)
	{
		(philo->tempo)++;
		if (philo->tempo >= ((table->n) / 2))
		{
			philo->tempo = 0;
			usleep(table->t_eat * 1000);
		}
	}
}

static void	routine_meal(t_philosopher *philo, t_table *table)
{
	long	nb_meal;

	if (pthread_create(&(philo->thread_death), NULL, routine_sem_death, philo))
		exit(1);
	if (table->n_to_eat == 0)
		sem_post(table->sem_meal);
	nb_meal = (long) table->n_to_eat - 1;
	while (1)
	{
		lock_forks(philo, table->forks);
		sem_wait(philo->sem_last_meal);
		philo->last_meal = time_lld(philo->table);
		print_status(1, philo->last_meal, philo->nb + 1);
		sem_post(philo->sem_last_meal);
		usleep((philo->table)->t_eat * 1000);
		unlock_forks(table->forks);
		print_status(2, time_lld(philo->table), philo->nb + 1);
		if (nb_meal-- == 0)
			sem_post(table->sem_meal);
		usleep((philo->table)->t_sleep * 1000);
		print_status(3, time_lld(philo->table), philo->nb + 1);
		new_tempo(philo, table);
	}
}

static void	routine_death(t_philosopher *philo, t_table *table)
{
	if (pthread_create(&(philo->thread_death), NULL, routine_sem_death, philo))
		exit(1);
	while (1)
	{
		lock_forks(philo, table->forks);
		sem_wait(philo->sem_last_meal);
		philo->last_meal = time_lld(philo->table);
		print_status(1, philo->last_meal, philo->nb + 1);
		sem_post(philo->sem_last_meal);
		usleep((philo->table)->t_eat * 1000);
		unlock_forks(table->forks);
		print_status(2, time_lld(philo->table), philo->nb + 1);
		usleep((philo->table)->t_sleep * 1000);
		print_status(3, time_lld(philo->table), philo->nb + 1);
		new_tempo(philo, table);
	}
}

void	routine(t_philosopher *philo, t_table *table)
{
	if (table->argc == 6)
		routine_meal(philo, table);
	else
		routine_death(philo, table);
}
