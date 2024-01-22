/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:39:22 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/21 18:39:28 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(char *arr, int fd)
{
    char    *str;
    int     sub; 

    if (arr)
        arr = ft_backup(arr);
    free(arr);
    arr = NULL;
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
        // printf("str = %s\n", arr);
        free(str);
        if (sub == 0)
            break ;
        if (ft_strchr(arr, '\n'))
            break ;
    }
    // printf("arr in= %s **\n",arr);
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
    
	reserve = ft_strdup(arr + ft_count(arr));
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
    // free(arr);
    return (str);
}

char    *get_next_line(int fd)
{
    static char *arr;
    char        *one;

    if (fd < 0)
        return  (NULL);
    arr = ft_read(arr, fd);
    one = ft_Myline(arr);
    if (one && *one == '\0')
        return (NULL);
    return (arr);
}

int main ()
{
	int fd = open("fd.txt", O_RDWR);
    // get_next_line(fd);
    // get_next_line(fd);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    // system("leaks a.out");
    close(fd);
    return 0;
}
