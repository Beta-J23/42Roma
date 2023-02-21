/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:33:34 by alpelliz          #+#    #+#             */
/*   Updated: 2023/02/15 17:40:59 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



int main()
{
	int		i;
	char	*test;
	
	test = "provartvycsddxzrehrtvehrehrtvdhrt";
	i = ft_strlen(test);
	ft_printf("TEST is of %d letters\n", i);
	return (0);
}