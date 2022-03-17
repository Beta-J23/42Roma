/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:25:45 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/15 15:14:23 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
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
		if ((*str >= 97) && (*str <= 122))
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
