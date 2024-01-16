#include "get_next_line.h"

char    *ft_read(char *arr, int fd)
{
    char    *str;
    char    *s;
    int     sub;
  
    if (arr)
    {
        free(arr);
        arr = ft_backup(arr);
    }
    while (1)
    {
        str = malloc(BUFFER_SIZE + 1);
        sub = read(fd, str, BUFFER_SIZE);
        str[sub] = '\0';
        arr = ft_strjoin(arr, str);
        if (sub == 0) 
            break ;
        if (str)
            free(str);
        if (ft_strchr(arr, '\n'))
                break ;
    }
    return (arr);
}

char    *ft_backup(char *arr)
{
    char    *reserve;
    int     i;

    i = 0;
    if (!arr)
        return (NULL);
    while (arr && arr[i])
    {
        if (arr[i] == '\n')
            break ;
        i++;
    }
    reserve = ft_strdup(arr +  i + 1);
    return (reserve);
}

char    *ft_line(char *arr)
{
    char    *str;
    int     i;

    i = 0;
    str = malloc(ft_strlen(arr));
    if (!str)
    {
        free(str);
        return (NULL);
    }
    while (arr && arr[i])
    {
        if (arr[i] == '\n')
            break ;
        str[i] = arr[i];
        i++;
    }
    return (str);
}

char    *get_next_line(int fd)
{
    static char *arr;
    char        *one;

    arr = ft_read(arr, fd);
    one = ft_line(arr);
    if (*one == '\0')
        return (NULL);
    return (one);
}

int main ()
{
    char *s;
    int fd = open("fd.txt", O_RDWR);
    s = get_next_line(fd);
    while (s != NULL)
    {
        printf("%s\n", s);
        s = get_next_line(fd);
    }
    return 0;
} 