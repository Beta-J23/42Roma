/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:31:20 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/15 15:17:49 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
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
		if (((*str >= 65) && (*str <= 90)))
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
