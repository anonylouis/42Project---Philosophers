/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:24:39 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:24:59 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_processes(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->n)
	{
		kill((table->tab_pid)[i], SIGKILL);
		i++;
	}
}

static void	*check_death(void *void_table)
{
	t_table			*table;
	unsigned int	i;

	table = (t_table *) void_table;
	sem_wait(table->sem_death);
	sem_post(table->sem_death_msg);
	i = 0;
	while (i < table->n)
	{
		sem_post(table->sem_meal);
		i++;
	}
	return (NULL);
}

static void	*check_meal(void *void_table)
{
	t_table			*table;
	unsigned int	i;

	table = (t_table *) void_table;
	i = 0;
	while (i < table->n)
	{
		sem_wait(table->sem_meal);
		i++;
	}
	sem_post(table->sem_death);
	return (NULL);
}

void	wait_processes(t_table *table)
{
	if (table->argc == 5)
	{
		if (pthread_create(&(table->check_death), NULL, check_death, table))
			exit(1);
		if (pthread_join(table->check_death, NULL))
			exit(1);
	}
	else
	{
		if (pthread_create(&(table->check_death), NULL, check_death, table))
			exit(1);
		if (pthread_create(&(table->check_meal), NULL, check_meal, table))
			exit(1);
		if (pthread_join(table->check_death, NULL))
			exit(1);
		if (pthread_join(table->check_meal, NULL))
			exit(1);
	}
	kill_processes(table);
}
