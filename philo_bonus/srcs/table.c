/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:17:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 13:59:55 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_tab_pid(t_table *table)
{
	table->tab_pid = malloc(table->n * sizeof(int));
	if (table->tab_pid == NULL)
	{
		free(table);
		return (0);
	}
	return (1);
}

static void	init_time_and_cst(t_table *table, int argc)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	table->start_sec = start_time.tv_sec;
	table->start_usec = start_time.tv_usec;
	table->argc = argc;
}

void	init_sem(t_table *table)
{
	sem_unlink("forks");
	sem_unlink("sem_meal");
	sem_unlink("sem_death");
	sem_unlink("sem_death_msg");
	table->forks = sem_open("forks", O_CREAT, 0644, table->n);
	if (table->forks == SEM_FAILED)
		exit(1);
	table->sem_meal = sem_open("sem_meal", O_CREAT, 0644, 0);
	if (table->sem_meal == SEM_FAILED)
		exit(1);
	table->sem_death = sem_open("sem_death", O_CREAT, 0644, 0);
	if (table->sem_death == SEM_FAILED)
		exit(1);
	table->sem_death_msg = sem_open("sem_death_msg", O_CREAT, 0644, 0);
	if (table->sem_death_msg == SEM_FAILED)
		exit(1);
}

t_table	*init_table(int argc, char **argv)
{
	t_table			*table;

	table = malloc(sizeof(t_table));
	if (table == NULL || !ft_atoi(argv[1], &(table->n)) || table->n == 0
		|| !ft_atoi(argv[2], &(table->t_death))
		|| !ft_atoi(argv[3], &(table->t_eat))
		|| !ft_atoi(argv[4], &(table->t_sleep))
		|| (argc == 6 && !ft_atoi(argv[5], &(table->n_to_eat)))
		|| (argc == 6 && table->n_to_eat == 0))
	{
		free(table);
		return (NULL);
	}
	if (!init_tab_pid(table))
		return (NULL);
	init_time_and_cst(table, argc);
	init_sem(table);
	return (table);
}

void	free_table(t_table *table)
{
	if (table)
	{
		sem_close(table->forks);
		sem_close(table->sem_meal);
		sem_close(table->sem_death);
		sem_close(table->sem_death_msg);
		sem_unlink("forks");
		sem_unlink("sem_meal");
		sem_unlink("sem_death");
		sem_unlink("sem_death_msg");
		free(table->tab_pid);
		free(table);
	}
}
