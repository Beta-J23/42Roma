/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:25:33 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/06 18:54:52 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1


int		ft_strlen(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin2(char *s1, char *s2);
char	*read_copy_string(int fd, char *save);
char	*extract_line(char *save);
char	*ft_cleanup(char *save);
char	*get_next_line(int fd);

#endif