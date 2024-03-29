/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_
.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:51 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/06 14:13:57 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_isdigit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static const char	*check_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (NULL);
	if (!ft_isdigit(&str[i]))
		return (NULL);
	return (&str[i]);
}

long	ft_atol(const char *str)
{
	long long int	result;
	int				i;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	str = check_str(str);
	if (!str)
		return (ERROR_ARG);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if ((result * sign) >= 2147483648 || (result * sign) <= -2147483649)
		return (ERROR_ARG);
	return (result * sign);
}
