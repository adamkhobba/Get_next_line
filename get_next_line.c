#include "get_next_line.h"
#include <fcntl.h>

char *ft_read(char *arr, int fd) {
  int sbuff;
  char *str;
  int i;

  str = (char *)malloc(BUFFER_SIZE + 1);
  sbuff = read(fd, str, BUFFER_SIZE);
  str[BUFFER_SIZE + 1] = '\0';
  if (sbuff < 0) {
    free(str);
    return ((void *)0);
  }
  if (!arr)
    arr = ft_strdup(str);
  i = 0;
  while (sbuff != 0) {
    if (str[i + BUFFER_SIZE] == '\n' && str[i + BUFFER_SIZE] == '\0')
      break;
    else {
      free(str);
      str = (char *)malloc(BUFFER_SIZE + i + 1);
      sbuff = read(fd, str, BUFFER_SIZE + i);
      if (sbuff == 0)
        break;
      str[BUFFER_SIZE + 1 + i] = '\0';
      arr = ft_strjoin(arr, str);
    }
    i++;
  }
  return (str);
}

char *get_next_line(int fd) {

  static char *arr;
  char *real;
  arr = ft_read(arr, fd);
  return (arr);
}

// int main() {
//   char *s;
//   char *arr;
//   arr = (char *)malloc(30);
//   s = (char *)malloc(30);
//   int fd = open("fd.txt", O_RDONLY);
//   int fb = read(fd, s, 12);
//   printf("s =%s$\n", s);
//   arr = ft_strdup(s);
//   free(s);
//   s = (char *)malloc(30);
//   fb = read(fd, s, 12);
//   printf("s =%s$\n", s);
//   printf("arr =%s\n", arr);
//   // char *a = ft_strjoin(s, arr);
//   printf("%s$", ft_strjoin(s, arr));
//   return (0);
// }
