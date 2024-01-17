/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:21 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/16 18:56:45 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char *ft_backup(char *arr);

#endif
