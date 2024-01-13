#include "get_next_line.h"
#include <fcntl.h>

char *ft_read(char *arr, int fd) {
  int sbuff;
  char *str;
  int i;

  str = (char *)malloc(BUFFER_SIZE + 1);
  // sbuff = read(fd, str, BUFFER_SIZE);
  // str[sbuff] = '\0';
  // if (sbuff < 0) {
  //   free(str);
  //   return ((void *)0);
  // }

  //puts(str);
  i = 0;
  while (1) {
    sbuff = read(fd, str, BUFFER_SIZE);
    str[sbuff] = '\0';
    arr = ft_strjoin(arr, str);
    puts(arr);
    if (sbuff == 0)
    {
      printf("---------\n");
      puts(arr);
      break;
    }
	  //puts(str);
    i++;
  }
  return (arr);
}

char *get_next_line(int fd) 
{
  static char *arr;
  char        *real;

  arr = ft_read(arr, fd);
  return (arr);
}

int main()
{
	int fd = open("fd.txt", O_RDONLY);
  get_next_line(fd);
  // printf("%s",get_next_line(fd));
	return 0;
}
/*int main() {
	char *s;
	char *arr;
	arr = (char *)malloc(30);
	s = (char *)malloc(30);
	int fd = open("fd.txt", O_RDONLY);
	int fb = read(fd, s, 12);
	//  printf("s =%s$\n", s);
	arr = ft_strdup(s);
	// free(s);
	// s = (char *)malloc(30);
	fb = read(fd, s, 12);
	printf("s =%s$\n", s);
	printf("arr =%s\n", arr);
	char *a = ft_strjoin(arr, s);
	printf("total = %s$", a);
	return (0);
}*/