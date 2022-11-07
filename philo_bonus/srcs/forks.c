/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:51:35 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 12:51:17 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philosopher *philo, sem_t *forks)
{
	sem_wait(forks);
	print_status(0, time_lld(philo->table), philo->nb + 1);
	sem_wait(forks);
	print_status(0, time_lld(philo->table), philo->nb + 1);
}

void	unlock_forks(sem_t *forks)
{
	sem_post(forks);
	sem_post(forks);
}
