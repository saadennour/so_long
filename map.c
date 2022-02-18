#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>


static int uno (char *s)
{
    int i = 0;
    int count = 0;

    while (s[i] != '\n')
    {
        if (s[i] == '1')
            count++;
        else
            exit(1);
        i++;
    }
    free (s);
    return (count);
}

static char *segundo (char *s, int count)
{
    if (s[0] == '1' && s[count - 1] == '1')
        return (s);
    exit(1);
}

static int player (char *s)
{
    int i = 0;

    while (s[i] != '\n')
    {
        if (s[i] == 'P')
            return (1);
        i++;
    }
    return (0);
}

static int collectible (char *s)
{
    int i;

    i = 0;
    while (s[i] != '\n')
    {
        if (s[i] == 'C')
        {
            free (s);
            return (1);
        }
        i++;
    }
    return (0);
}

static int out (char *s)
{
    int i;

    i = 0;
    while (s[i] != '\n')
    {
        if (s[i] == 'E')
        {
            free (s);
            return (1);
        }
        i++;
    }
    return (0);
}

// int check_map(int fd)
// {
//     int count = 0;
//     int line = 0;
//     int p = 0;
//     int c = 0;
//     int e = 0;
//     char *s = NULL;
//     char *ob = NULL;

//     s = get_next_line(fd, 13);
//     count = uno(s);
//     while ((s = get_next_line(fd, 13)))
//     {
//         ob = segundo(s, count);
//         p += player(s);
//         c += collectible(s);
//         e += out(s);
//         line++;
//     }
//     count = uno(ob);
//     //printf ("%d , %d , %d", p,c,e);
//     if (p == 1 && c >= 1 && e == 1)
//         return (1);
//     return (0);
// }

// int main()
// {
// 	int fd;
//     int nbr = 0;

// 	fd = open ("map.ber", O_RDWR);
//     nbr = check_map(fd);
//     printf ("%d", nbr);
//     system ("Leaks a.out");
// }