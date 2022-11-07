/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:51:35 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:38:57 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philosopher *philo)
{
	unsigned int	left;

	if (philo->nb != 0)
		left = philo->nb - 1;
	else
		left = (philo->table)->n - 1;
	if (philo->nb > left)
	{
		pthread_mutex_lock(&(((philo->table)->forks)[left]));
		print_status(philo->table, 0, time_lld(philo->table), philo->nb + 1);
		pthread_mutex_lock(&(((philo->table)->forks)[philo->nb]));
		print_status(philo->table, 0, time_lld(philo->table), philo->nb + 1);
	}
	else
	{
		pthread_mutex_lock(&(((philo->table)->forks)[philo->nb]));
		print_status(philo->table, 0, time_lld(philo->table), philo->nb + 1);
		pthread_mutex_lock(&(((philo->table)->forks)[left]));
		print_status(philo->table, 0, time_lld(philo->table), philo->nb + 1);
	}
}

void	unlock_forks(t_philosopher *philo)
{
	unsigned int	left;

	if (philo->nb != 0)
		left = philo->nb - 1;
	else
		left = (philo->table)->n - 1;
	if (philo->nb > left)
	{
		pthread_mutex_unlock(&(((philo->table)->forks)[philo->nb]));
		pthread_mutex_unlock(&(((philo->table)->forks)[left]));
	}
	else
	{
		pthread_mutex_unlock(&(((philo->table)->forks)[left]));
		pthread_mutex_unlock(&(((philo->table)->forks)[philo->nb]));
	}
}
