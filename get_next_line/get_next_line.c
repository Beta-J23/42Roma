/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:47:29 by alpelliz          #+#    #+#             */
/*   Updated: 2023/01/25 16:10:44 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int counter;
int     x = 2;

char *get_next_line(int fd)
{
    return (0);
}

int main()
{
    int fd;
    char *line;

    fd = open("ciao.c", O_RDONLY);
    while (line = get_next_line(fd))
    {
        printf("%s", line);
    }
    x += ft_strlen("ciaone");
    x += ft_strlen("ciaone");
    printf("%d\n", x);
}