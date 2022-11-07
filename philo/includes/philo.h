/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:56:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:32:08 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "table.h"

typedef struct s_philosopher
{
	pthread_t		thread;
	unsigned int	nb;
	long long		last_meal;
	pthread_mutex_t	mtx_last_meal;
	unsigned int	tempo;
	t_table			*table;
}		t_philosopher;

//TABLE
t_table			*init_table(int argc, char **argv);
void			free_table(t_table *table);

//PHILO
t_philosopher	*init_tab_philo(t_table *table);
void			free_tab_philo(t_philosopher *tab_philo, unsigned int N);

//THREAD
int				start_threads(t_philosopher *tab_philo, t_table *table);
int				wait_threads(t_table *table);
void			*stop(void *void_tab_philo);

//ROUTINE
void			*routine_one(void *void_philo);
void			*routine_odd(void *void_philo);
void			*routine_odd_last(void *void_philo);
void			*routine_even(void *void_philo);
void			*routine_even_last(void *void_philo);

//FORKS
void			lock_forks(t_philosopher *philo);
void			unlock_forks(t_philosopher *philo);

//UTILS
int				ft_atoi(char *str, unsigned int *n);
long long		time_lld(t_table *table);
unsigned int	ft_min(unsigned int a, unsigned int b);
void			print_status(t_table *table, int status,
					long long time, unsigned int nb);

#endif