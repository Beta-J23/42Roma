/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:36:34 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/15 15:36:27 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				cond;

	cond = 1;
	i = 0;
	while (i < n)
	{
		if (src[i] != '\0' && cond == 1)
			dest[i] = src[i];
		else
			cond = 0;
		if (cond == 0)
			dest[i] = '\0';
		i++;
	}
	return (dest);
}
