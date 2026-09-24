#include "get_next_line.h"

char *save_last_str(char *str)
{
    char *new_s;
    size_t size;
    size_t i;
    int j;
    if (!str)
    {
        return NULL;
    }
    i = 0;
    j = 0;
    while (str[i] && str[i] != '\n')
    {
        i++;
    }
    if (str[i] == '\n')
    {
        i++;
    }
    if (str[i] == '\0')
    {
        return NULL;
    }
    size = ft_strlen((str + i));
    new_s = malloc(size + 1);
    if (!new_s)
    {
        return NULL;
    }
    while (str[i])
    {
        new_s[j] = str[i];
        i++;
        j++;
    }
    new_s[j] = '\0';
    return new_s;
}
char *find_lein(char *str)
{
    size_t size;
    size_t i;
    char *new_str;
    if (!str)
    {
        return NULL;
    }
    size = 0;
    i = 0;
    while (str[size] && str[size] != '\n')
    {
        size++;
    }
    if (str[size] == '\n')
    {
        size++;
    }
    new_str = malloc(size + 1);
    if (!new_str)
    {
        return NULL;
    }
    while (i < size)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}

char *get_next_line(int fd)
{
    static char *stash;
    char *new_stash;
    char *buffer;
    ssize_t bytes_read;
    char *lein;

    if ((read(fd, NULL, 0) == -1) || (BUFFER_SIZE <= 0) || fd == -1)
    {
        return (NULL);
    }
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
    {
        return NULL;
    }
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        if (stash == NULL)
        {
            stash = ft_strdup(buffer);
             if (!stash)
            {
                free(buffer);
                free(stash);
                return NULL;
            }
        }
        else
        {
            new_stash = ft_strjoin(stash, buffer);
            if (!new_stash)
            {
                free(buffer);
                free(stash);
                return NULL;
            }
            free(stash);
            stash = new_stash;
        }
        if (ft_strchr(stash, '\n') != NULL)
        {
            break;
        }
    }
    if (bytes_read == 0 && stash == NULL)
    {
        free(buffer);
        return NULL;
    }
    else if (bytes_read == -1)
    {
        free(stash);
        free(buffer);
        return NULL;
    }
    
    lein = find_lein(stash);
    new_stash = save_last_str(stash);
    free(stash);
    stash = new_stash;
    free(buffer);
    return lein;
}
int main(void)
{
    int fd;

    fd = open("test.txt", O_RDONLY);

    printf("1: %s", get_next_line(fd));
    printf("2: %s", get_next_line(fd));
    printf("3: %s", get_next_line(fd));
    printf("4: %s", get_next_line(fd));
    printf("5: %s", get_next_line(fd));

    close(fd);
    return (0);
}