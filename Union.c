#include <unistd.h>

int check_repeat(char *str, char c, int n)
{
    int i = 0;
    
    while(i < n)
    {
        if(str[i] == c)
            return(0);
        i++;
    }
    return(1);
}

void ft_strcat(char *s1, char *s2)
{
    int i = 0, j = 0;
    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

int main(int argc, char *argv[])
{
    int i, j;
    
    i = 0;
    if (argc == 3)
    {
        ft_strcat(argv[1], argv[2]);
        while (argv[1][i] != '\0')
        {
            if(check_repeat(argv[1], argv[1][i], i))
            {
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
