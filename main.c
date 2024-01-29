#include "get_next_line.h"
int main ()
{
    int fd = open("t", O_RDONLY);
    char *s = get_next_line(fd);
    while (s)
    {
        printf("%s", s);
        s = get_next_line(fd);

    }

}