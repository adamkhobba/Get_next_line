    #ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_  H
#define BUFFER_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char *ft_backup(char *arr);

#endif
