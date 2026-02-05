/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:02:15 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/17 18:56:37 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	int 	i;
	int		j;
	j = 1;
	i = 0;
	while (j < argc)
	{
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] >= 97 && argv[j][i] <= 122)
				argv[j][i] = (argv[j][i] - 32);
			std::cout <<  argv[j][i];
			i++;
		}
		std::cout << " ";
		i = 0;
		j++;
	}
	std::cout << '\n';
	return (0);
}
