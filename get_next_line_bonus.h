/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:59:21 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/26 14:44:49 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strdup(char *s);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, char *src, size_t size);
char    *ft_strchr(char *s, int c);
char    *ft_backup(char *arr);
char    *ft_substr(char *s, size_t i, size_t len);
#endif
