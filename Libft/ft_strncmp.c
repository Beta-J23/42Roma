/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:28:12 by alpelliz          #+#    #+#             */
/*   Updated: 2022/03/17 15:26:53 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int temp;
	int	i;

	temp = 0;
	i = 0;
	while (s1[i] != '\0'/* && (s1[i] == s2[i])*/ && i < (int)n)
	{
		temp = temp + (s1[i] - s2[i]);
		i++;
	}
	return (temp);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    //printf("%d", strncmp("acdce", "adcf", 2));
    printf("%d", ft_strncmp("aafce", "zbcde", 3)); 
}
*/