/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:07:49 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/19 12:48:48 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_philo(t_arg *arg)
{
	int	i;

	i = 0;
	arg->philos = malloc(sizeof(t_philo) * arg->number_of_philosophers);
	if (!arg->philos)
		return (p_error(ERROR_MALLOC, arg), 0);
	while (i < arg->number_of_philosophers)
	{
		arg->philos[i].id = i + 1;
		arg->philos[i].left_fork = i;
		arg->philos[i].right_fork = (i + 1) % arg->number_of_philosophers;
		arg->philos[i].nb_eat = 0;
		arg->philos[i].arg = arg;
		i++;
	}
	return (1);
}

static int	init_mutex(t_arg *arg)
{
	int	i;

	i = -1;
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->number_of_philosophers);
	if (!arg->forks)
		return (p_error(ERROR_MALLOC, arg), 0);
	while (++i < arg->number_of_philosophers)
	{
		if (pthread_mutex_init(&arg->forks[i], NULL))
			return (destroy_mutex(arg, i), 0);
	}
	if (pthread_mutex_init(&arg->philo_status, NULL))
		return (destroy_mutex(arg, arg->number_of_philosophers), 0);
	if (pthread_mutex_init(&arg->dead, NULL))
		return (destroy_mutex(arg, arg->number_of_philosophers), 0);
	return (1);
}

static int	check_arg(t_arg *arg)
{
	if (arg->number_of_philosophers < 0
		|| arg->number_of_philosophers > 200
		|| arg->time_to_die < 60
		|| arg->time_to_eat < 60
		|| arg->time_to_sleep < 60
		|| arg->nb_eat_limit == 0)
		return (0);
	return (1);
}

int	init_arg(int argc, char **argv, t_arg *arg)
{
	if (argc == 5 || argc == 6)
	{
		arg->number_of_philosophers = ft_atol(argv[1]);
		arg->time_to_die = ft_atol(argv[2]);
		arg->time_to_eat = ft_atol(argv[3]);
		arg->time_to_sleep = ft_atol(argv[4]);
		arg->start_simulation = get_current_time(0);
		if (argc == 6)
		{
			if (ft_atol(argv[5]) == ERROR_ARG)
				return (0);
			arg->nb_eat_limit = ft_atol(argv[5]);
		}
		else
			arg->nb_eat_limit = -1;
		if (!check_arg(arg))
			return (0);
		if (!init_mutex(arg))
			return (0);
		return (1);
	}
	return (0);
}
