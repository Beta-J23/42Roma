/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:00:25 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/16 16:22:39 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
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
		if ((*str >= 32) && (*str < 127))
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
