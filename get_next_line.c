#include "get_next_line.h"
#include <fcntl.h>

char *ft_read(char *arr, int fd) {
  int sbuff;
  int nsbuff;
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
  {
    arr = ft_strdup(str);
  }
  i = 0;
  while (i < 3) {
  //  if (str[i + BUFFER_SIZE] == '\n' && str[i + BUFFER_SIZE] == '\0')
  	//   break;
  //  else {
     // free(str);
     // str = (char *)malloc(BUFFER_SIZE + i + 1);
      nsbuff = read(fd, str, BUFFER_SIZE);
    //   if (nsbuff == 0)
	  // {
    //     break;
	  // }
      str[nsbuff] = '\0';
	puts(str);
      arr = ft_strjoin(arr, str);
    i++;
  }
  return (arr);
}

char *get_next_line(int fd) {

  static char *arr;
  char *real;
  arr = ft_read(arr, fd);
  return (arr);
}

int main()
{
	int fd = open("fd.txt", O_RDONLY);
  printf("%s",get_next_line(fd));
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