/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:32:14 by alpelliz          #+#    #+#             */
/*   Updated: 2022/02/24 10:52:53 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	(void) argc;
	i = 0;
	j = 1;
	while (argv[j] != '\0')
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			print(argv[j][i]);
			i++;
		}
		print('\n');
		j++;
	}
}
