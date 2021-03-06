/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:10:55 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/16 18:18:25 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65) && (str[i] <= 90))
				str[i] = (str[i] + 32);
		if (((str[i - 1] < 48) || ((str[i - 1] > 57)
					&& (str[i - 1] < 65)) || (str[i - 1] > 122))
			|| ((str[i - 1] > 90) && (str[i - 1] < 97)))
			if ((str[i] >= 97) && (str[i] <= 122))
						str[i] = (str[i] - 32);
		i++;
	}
	return (str);
}
