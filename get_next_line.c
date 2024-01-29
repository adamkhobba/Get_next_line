/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:39:22 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/29 15:00:38 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	return (0);
}

char	*ft_read(char *arr, int fd)
{
	char	*str;
	int		sub;

	sub = 1;
	str = malloc((size_t)BUFFER_SIZE + (size_t)1);
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

char	*ft_line(char *arr)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!arr)
		return ((void *)0);
	if (*arr == '\0')
		return (NULL);
	while (arr && arr[k] && arr[k] != '\n')
		k++;
	str = malloc(k + 2);
	if (!str)
		return (NULL);
	while (arr && arr[i] && i < k + 1)
	{
		str[i] = arr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_backup(char *arr)
{
	char	*reserve;
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr && arr[i] && arr[i] != '\n')
		i++;
	if (i == ft_strlen(arr))
	{
		free(arr);
		return (NULL);
	}
	reserve = ft_strdup(arr + (i + 1));
	free(arr);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*arr;
	char		*one;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647 || fd < 0)
		return (NULL);
	arr = ft_read(arr, fd);
	one = ft_line(arr);
	arr = ft_backup(arr);
	if (one && *one == '\0')
		return (NULL);
	return (one);
}
int main()
{
	int fd = open("t", O_RDONLY);
	// char *s = get_next_line(fd);
	// while (s)
	// {
	char *s;
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		free(s);
		s = get_next_line(fd);
		free(s);
		s = get_next_line(fd);
		free(s);
		s = get_next_line(fd);
		free(s);
	system("leaks a.out");
	// }
	return 0;
}
