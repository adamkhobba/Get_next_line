/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:03:48 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/27 13:50:32 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *ft_read(char *arr, int fd)
{
    char    *str;
    int     sub; 

    sub = 1;
    // printf("dg\n");
    str = malloc(BUFFER_SIZE + 1);
    if (!str)
      return (NULL);
    while (sub && !ft_strchr(arr, '\n'))
    {
      sub = read(fd, str, BUFFER_SIZE);
	    if (sub == -1)
		  {
		  	free(arr);
		  	free(str);
		  	return (NULL);
		  }
      str[sub] = '\0';
      arr = ft_strjoin(arr, str);
      if (!arr)
        return (NULL);
  }
    free(str);
    return (arr);
}

size_t ft_count(char *arr)
{
  size_t i;

  i = 0; 
  while (arr  && arr[i] && arr[i] != '\n')
      i++;
  return (i);
}

char *ft_line(char *arr)
{
  char *str; 
  size_t i;

  i = 0;
  if (!arr)
    return ((void *)0);
  if (*arr == '\0')
    return (NULL);
  str = malloc(ft_count(arr) + 2);
  if (!str)
    return(NULL);
  while (arr && arr[i] && i < ft_count(arr) + 1)
  {
    str[i] = arr[i];
    i++;
  }
  str[i] = '\0';
  return (str);
}

char *ft_backup(char *arr)
{
  char *reserve;
  
  if (!arr)
    return (NULL);
  if (ft_count(arr) == ft_strlen(arr))
  {
    free(arr);
    return(NULL);
  }
  reserve = ft_strdup(arr + (ft_count(arr) + 1));
  free(arr);
  return (reserve);
}

char  *get_next_line(int fd)
{
  static char *arr[1024];
  char *one;

  // arr = (char **)malloc(fd * 100 *sizeof(char *));
  if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647 || fd > 1025)
		return (NULL);
  arr[fd] = ft_read(arr[fd], fd);
  one = ft_line(arr[fd]);
  arr[fd] = ft_backup(arr[fd]);
  if (one && *one == '\0')
    return (NULL);
  return (one);
}

// int main()
// {
//   int fd = open("fd.txt", O_RDWR);
//   printf("%i", fd);
//   char *s = get_next_line(fd);
//   printf("%s",s);
//   int fd1 = open("fd1.txt", O_RDWR);
//   printf("%i", fd1);
//   s = get_next_line(fd1);
//   printf("%s",s);
//   return 0;
// }
