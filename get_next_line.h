#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 13

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
int ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);

#endif
