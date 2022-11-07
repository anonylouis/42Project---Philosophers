/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:56:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:12:20 by lcalvie          ###   ########.fr       */
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
# include <semaphore.h>
# include <wait.h>
# include <signal.h>
# include <fcntl.h>
# include "table.h"

typedef struct s_philosopher
{
	pthread_t		thread_death;
	unsigned int	nb;
	long long		last_meal;
	sem_t			*sem_last_meal;
	unsigned int	tempo;
	t_table			*table;
}		t_philosopher;

//TABLE
t_table			*init_table(int argc, char **argv);
void			free_table(t_table *table);

//PHILO
t_philosopher	*init_tab_philo(t_table *table);
void			free_tab_philo(t_philosopher *tab_philo, unsigned int N);

//PROCESSES
void			start_processes(t_philosopher *tab_philo, t_table *table);
void			wait_processes(t_table *table);

//ROUTINE
void			routine(t_philosopher *philo, t_table *table);

//FORKS
void			lock_forks(t_philosopher *philo, sem_t *forks);
void			unlock_forks(sem_t *forks);

//UTILS
int				ft_atoi(char *str, unsigned int *n);
long long		time_lld(t_table *table);
unsigned int	ft_min(unsigned int a, unsigned int b);
void			print_status(int status, long long time, unsigned int n);
char			*ft_itoa(unsigned int n);

#endif