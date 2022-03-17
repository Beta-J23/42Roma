/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:19:36 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/15 15:11:15 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	verita;

	if (*str == '\0')
	{
		verita = 1;
		return (verita);
	}
	verita = 0;
	while (*str)
	{
		if ((*str >= 48) && (*str <= 57))
			verita = 1;
		else
		{
			verita = 0;
			return (verita);
		}
	str++;
	}
	return (verita);
}
