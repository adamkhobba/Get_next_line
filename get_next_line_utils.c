#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2) {
  size_t l1;
  size_t l2;
  char *p;

  if (!s1 && !s2)
    return (NULL);
  else if (!s1)
    return (ft_strdup(s2));
  else if (!s2)
    return (ft_strdup(s1));
  l1 = ft_strlen(s1);
  l2 = ft_strlen(s2);
  p = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
  if (!p)
    return (NULL);
  ft_strlcpy(p, s1, l1 + 1);
  ft_strlcpy(p + l1, s2, l2 + 1);
  return (p);
}

char *ft_strdup(const char *s) {
  char *ptr;
  char *put;
  size_t i;

  i = 0;
  ptr = (char *)s;
  put = (char *)malloc(ft_strlen(s) + 1);
  if (put == NULL)
    return (0);
  while (ptr[i]) {
    put[i] = ptr[i];
    i++;
  }
  put[i] = '\0';
  return (put);
}

int ft_strlen(const char *s) {
  int i;
  while (s[i] != '\0')
    i++;
  return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size) {
  size_t i;
  size_t l;

  i = 0;
  l = ft_strlen(src);
  if (size == 0)
    return (l);
  while (i < size - 1 && src[i]) {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return (l);
}

int main() {
  char const s[] = "adam";
  char const a[] = "khobba";

  // char *d = ft_strjoin(a, s);
  printf("%s", ft_strjoin(a, s));
  return (0);
}
