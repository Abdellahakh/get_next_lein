#ifndef GET_NEXT_LEIN_H
#define GET_NEXT_LEIN_H

#if !defined(BUFFER_SIZE)
#define BUFFER_SIZE 10
#endif


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);
size_t ft_strlen(char *str);
char *ft_strchr(char *str, char c);
char *ft_strdup(char *str);
char *ft_strjoin(char *str1, char *str2);
char *save_last_str(char *str);
char *find_lein(char *str);

#endif