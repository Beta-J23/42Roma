#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
//#define BUFFER_SIZE 50
#endif


int     ft_strlen(char *s);
size_t    gnl_strlen(char *str);
char    *get_next_line(int fd);
char    *ft_get_line(char *save);
char    *ft_backup(char *save);
char    *ft_strchr(char *s, char c);
char    *gnl_strchr(char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strjoin2(char *s1, char *s2);
char    *gnl_strjoin(char *s1, char *s2);
char    *ft_backup(char *save);
size_t    gnl_strlen(char *str);
char    *gnl_strchr(char *s, int c);
char    *read_string(int fd);

#endif
