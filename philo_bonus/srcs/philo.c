/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:07:10 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 13:59:55 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static sem_t	*init_sem_last_meal(unsigned int i)
{
	char	*sem_name;
	sem_t	*sem_last_meal;

	sem_name = ft_itoa(i);
	if (sem_name == NULL)
		exit(1);
	sem_unlink(sem_name);
	sem_last_meal = sem_open(sem_name, O_CREAT, 0644, 1);
	if (sem_last_meal == SEM_FAILED)
		exit(1);
	free(sem_name);
	return (sem_last_meal);
}

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
		(tab_philo[i]).sem_last_meal = init_sem_last_meal(i);
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
		sem_close((tab_philo[i]).sem_last_meal);
		i++;
	}
	free(tab_philo);
}
