#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include<stdlib.h>

#define BS 1

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return(i);
}

void *ft_memcpy(char *d, char *s, int n)
{
    char *td;
    char *ts;

    td = d;
    ts = s;
    while (n > 0)
    {
        *td = *ts;
        td++;
        ts++;
        n--;
    }
    return(d);
}

char *ft_strjoin(char *s1, char *s2)
{
    int s1l = ft_strlen(s1);
    int s2l = ft_strlen(s2);
    char *str;

    if(!s1)
        return(NULL);
    str = malloc(s1l + s2l + 1);
    if(!str)
    {
        free (s1);
        return (NULL);
    }
    ft_memcpy(str, s1, s1l);
    ft_memcpy(str + s1l, s2, s2l);
    free(s1);
    str[s1l + s2l] = '\0';
    return(str);
}

int get_line(char *buf, char *ln, int fd, int *flag)
{
    int i = 0;
    int rd = 1;

    while(rd > 0 && i < BS)
    {
        rd = read(fd, buf + i, 1);
        if (rd == -1)
        {
            free(buf);
            free(ln);
            return (1);
        }
        if (rd == 0 || buf[i++] == '\n')
        {
            *flag = 0;
            break;
        }
    }
    buf[i] = '\0';
    return (0);
}

char *get_next_line(int fd)
{
    static char *buf[1024];
    char *str;
    int flag = 1;

    if (fd < 0 || BS <= 0)
        return (NULL);
    buf[fd] = malloc(BS+1);
    if(!buf[fd])
        return (NULL);
    str = malloc(1);
    while(flag != 0)
    {
        if (get_line(buf[fd], str, fd, &flag) == 1)
            return(NULL);
        if (!ft_strlen(str) && !ft_strlen(buf[fd]))
        {
            free (str);
            str = NULL;
        }
        str = ft_strjoin(str, buf[fd]);
    }
    free(buf[fd]);
    return (str);
}
