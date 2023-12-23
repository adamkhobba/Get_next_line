#include "get_next_line.h"
#include <fcntl.h>

char *ft_read(char *arr, int fd) {
  int sbuff;
  char *str;
  int i;

  str = (char *)malloc(BUFFER_SIZE + 1);
  str[BUFFER_SIZE + 1] = '\0';
  sbuff = read(fd, str, BUFFER_SIZE);
  // printf("%s", str);
  arr = (char *)malloc(sbuff + 2);
  i = 0;
  while (str[i] != '\0' && str[i] != '\n') {
    arr[i] = str[i];
    i++;
  }
  return (arr);
}

char *get_next_line(int fd) {

  static char *arr;
  char *real;
  real = ft_read(arr, fd);
  return real;
}
int main() {
  printf("%s", get_next_line(3));
  return 0;
}
