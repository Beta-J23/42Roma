/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:59:40 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/15 15:06:56 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
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
		if (((*str >= 65) && (*str <= 90))
			|| ((*str >= 97) && (*str <= 122)))
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
