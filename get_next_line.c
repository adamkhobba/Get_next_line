/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:28:38 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/19 22:49:53 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(char *arr, int fd)
{
    char    *str;
    int     sub;
    
    arr = ft_backup(arr);
    while (1)
    {
        str = malloc(BUFFER_SIZE + 1);
        sub = read(fd, str, BUFFER_SIZE);
        str[sub] = '\0';
        arr = ft_strjoin(arr, str);
        free(str);
        // puts(arr);
        if (sub == 0)
            break ;
        if (ft_strchr(arr, '\n'))
            break ;
    }
    return (arr);
}
int ft_count(char *str)
{
    int i;
    
    i = 0;
    while (str && str[i] && str[i] != '\n')
    {
        i++;
    }   
    return (i);
}
char    *ft_backup(char *arr)
{
    char *reserve;
    
    if (!arr)
        return (NULL);
    reserve = ft_strdup(arr + ft_count(arr));
    // printf("%d", ft_count(arr));
    // printf("%s", reserve);
    free(arr);
    return (reserve);
}
char    *ft_Myline(char *arr)
{
    char    *str;
    int     i;

    i = 0;
    str = malloc(ft_count(arr) + 1);
    while (arr && arr[i] && i < ft_count(arr) + 1)
    {
        str[i] = arr[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
char    *get_next_line(int fd)
{
    static char *arr;
    char        *one;

    arr = ft_read(arr, fd);
    one = ft_Myline(arr);
    return (one);
}
int main ()
{
    int fd = open("fd.txt", O_RDWR);
    // get_next_line(fd);
    get_next_line(fd);
    printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    close(fd);
    return 0;
}