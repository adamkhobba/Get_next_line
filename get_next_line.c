#include "get_next_line.h"

char *ft_read(char *arr, int fd)
{
char    *str;
int     sub;
int check ;

check = 0;
while (1)
{
    if (str)
        free(str);
    str = malloc(BUFFER_SIZE + 1);
    sub = read(fd, str , BUFFER_SIZE);
    str[sub] = '\0';
    if (sub == 0)
        break ;
    arr = ft_strjoin(arr, str);
    int i = 0;
    while(arr[i])
    {
        if (arr[i] == '\n')
        {
            check = 1;
                break ;
            }  
            ++i;
        }
        if (1 == check)
            break ;
        //printf("-------------\n");
         //puts(arr);
    }
    return (arr);
}

ft_MovethN(char *str, char *str2)
{
    char     


}
char *get_next_line(int fd)
{
static char *arr;
char        *Iamtheone;

    arr = ft_read(arr,fd);
    Iamtheone = ft_MovetheN(arr, Iamtheone); 
    return (arr);
}

int main ()
{
    int fd = open("fd.txt", O_RDWR);
    //  get_next_line(fd);
    printf("%s", get_next_line(fd));
    return 0;
}