/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:07:10 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:28:08 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*init_tab_philo(t_table *table)
{
	t_philosopher	*tab_philo;
	unsigned int	i;

	tab_philo = malloc(table->n * sizeof(t_philosopher));
	if (tab_philo == NULL)
	{
		free_table(NULL);
		return (NULL);
	}
	i = 0;
	while (i < table->n)
	{
		(tab_philo[i]).nb = i;
		(tab_philo[i]).table = table;
		(tab_philo[i]).tempo = i / 2;
		(tab_philo[i]).last_meal = 0;
		pthread_mutex_init(&((tab_philo[i]).mtx_last_meal), NULL);
		i++;
	}
	(tab_philo[table->n - 1]).tempo = 0;
	return (tab_philo);
}

void	free_tab_philo(t_philosopher *tab_philo, unsigned int N)
{
	unsigned int	i;

	i = 0;
	while (i < N)
	{
		pthread_mutex_destroy(&((tab_philo[i]).mtx_last_meal));
		i++;
	}
	free(tab_philo);
}
