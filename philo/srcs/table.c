/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:17:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:28:08 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_table *table)
{
	table->forks = malloc(table->n * sizeof(pthread_mutex_t));
	if (table->forks == NULL)
	{
		free(table);
		return (0);
	}
	return (1);
}

static int	init_mutex(t_table *table)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < table->n)
	{
		if (pthread_mutex_init(&((table->forks)[i]), NULL) != 0)
		{
			j = 0;
			while (++j < i)
				pthread_mutex_destroy(&((table->forks)[j]));
			free_table(table);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	init_time_and_cst(t_table *table, int argc)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	table->start_sec = start_time.tv_sec;
	table->start_usec = start_time.tv_usec;
	table->can_talk = 1;
	pthread_mutex_init(&(table->mtx_talk), NULL);
	table->number_meal = 0;
	pthread_mutex_init(&(table->mtx_number_meal), NULL);
	table->argc = argc;
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
	if (!init_forks(table))
		return (NULL);
	if (!init_mutex(table))
		return (NULL);
	init_time_and_cst(table, argc);
	return (table);
}

void	free_table(t_table *table)
{
	unsigned int	i;

	if (table)
	{
		i = 0;
		while (++i < table->n)
			pthread_mutex_destroy(&((table->forks)[i]));
		pthread_mutex_destroy(&(table->mtx_number_meal));
		pthread_mutex_destroy(&(table->mtx_talk));
		free(table->forks);
		free(table);
	}
}
