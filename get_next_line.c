/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:44 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/19 10:25:58 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(char *arr, int fd)
{
    char    *str;
    int     sub;
  
    if (arr)
    {
        arr = ft_backup(arr);
    }
    while (1)
    {        

        str = malloc((size_t)BUFFER_SIZE + 1);
        if (!str)
        {
            free(str);
            return (NULL);
        }
        sub = read(fd, str, BUFFER_SIZE);
        str[sub] = '\0';
        arr = ft_strjoin(arr, str);
        puts(arr);
        free(str);
        if (sub == 0)
            break ;
        if (ft_strchr(arr, '\n'))
                break ;
    }
    return (arr);
}

int ft_count(char *arr)
{
    int i;
    
    i = 0;
    while (arr && arr[i])
    {
        if (arr[i] == '\n')
            break ;
        i++;
    }
    return (i);
}
char    *ft_backup(char *arr)
{
    char    *reserve;

    if (!arr)
        return (NULL);
    reserve = ft_strdup(arr + ft_count(arr) + 1);

    free(arr);
    return (reserve);
}

char    *ft_line(char *arr)
{
    char    *str;
    int     i;

    i = 0;
    // puts(arr);
    str = malloc(ft_count(arr) + 1);
    if (!str)
        return (NULL);
    while (arr && arr[i] && i < ft_count(arr) + 1)
    {
      str[i] = arr[i];
        i++;
    }
    str[i] = '\0';
    // printf("%s", arr);
    free(str);
    return (str);
}

char    *get_next_line(int fd)
{
    static char *arr;
    char        *one;
    
    if(BUFFER_SIZE < 0 || fd < 0)
        return 0;
        
        
    arr = ft_read(arr, fd);
    one = ft_line(arr);
    
    if (one && *one == '\0')
        return (NULL);
    return (one);
}
// It's my own code ^_^
int main ()
{
    char *s;
    int fd = open("fd.txt", O_RDWR);
    s = get_next_line(fd);
    // printf("%s", s);
    s = get_next_line(fd);   
    // printf("%s", s);
    // s = get_next_line(fd);
    // printf("%s", s);
    // system("leaks a.out");
    return 0;
}
    