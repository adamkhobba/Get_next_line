#include "get_next_line.h"

char *ft_read(char *arr, int fd)
{
    char    *str;
    char    *s;
    int     sub;
    int     check;
    int     i;

    i = 0;
  
    if (arr)
    {
        free(arr);
        arr = NULL;
    }
    while (1)
    {
        if (str)
            free(str);
        str = malloc(BUFFER_SIZE + 1);
        sub = read(fd, str , BUFFER_SIZE);
        str[sub] = '\0';
        arr = ft_strjoin(arr, str);
        if (sub == 0)
            break ;
        if (ft_strchr(arr, '\n'))
                break ;
    }
    return (arr);
}

char *ft_backup(char *arr)
{
    char *reserve;
    int i;

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
    // printf("$%d$", (strlen(arr) - i));
    return (reserve);
}

char *ft_MovetheN(char *str)
{
    int i;
    char *str2;

    i = 0;

    str2 = malloc(ft_strlen(str));
    while (str[i])
    {   
        if (str[i] == '\n')
            break ;
        str2[i] = str[i];
        ++i;
    }
    // puts(str2);
    return (str2);
}

char *get_next_line(int fd)
{
    static char *arr;
    char        *one;

    arr = ft_read(arr,fd);
    one = ft_MovetheN(arr);
    return (arr);
}

int main ()
{
    int fd = open("fd.txt", O_RDWR);
    get_next_line(fd);
    // printf("%s", get_next_line(fd));
    printf("\n$%s$", get_next_line(fd));
    //printf("\n%s", get_next_line(fd));
    return 0;
}