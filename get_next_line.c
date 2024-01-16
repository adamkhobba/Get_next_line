/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:44 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/16 15:41:48 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        if (!str)
        {
            free(str);
            return (NULL);
        }
        sub = read(fd, str, BUFFER_SIZE);
        str[sub] = '\0';
        arr = ft_strjoin(arr, str);
        printf("location of str in ft_read is =%p\n",str);
        free(str);
        if (sub == 0)
            break ;
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
    reserve = ft_strdup(arr + i + 1);
    return (reserve);
}

char    *ft_line(char *arr)
{
    char    *str;
    int     i;

    i = 0;
    str = malloc(ft_strlen(arr));
    // if (ft_free(str))
    //     return (NULL);
    while (arr && arr[i])
    {
        str[i] = arr[i];
        if (arr[i] == '\n')
            break ;
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
    // printf(" location of arr if get...is =%p\n",arr);
    if (*one == '\0')
        return (NULL);
    return (one);
}
// My own code :)
int main ()
{
    char *s;
    int fd = open("fd.txt", O_RDWR);
    s = get_next_line(fd);
    while (s != NULL)
    {
        printf("%s", s);
        s = get_next_line(fd);
    }
    system("leaks a.out");
    return 0;
}