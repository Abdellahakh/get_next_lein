#include "get_next_line.h"
size_t ft_strlen(char *str)
{
    size_t i;
    i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}
char *ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != c && str[i])
    {
        i++;
    }
    if(str[i] == c)
    {
        return (&str[i]);
    }
    return NULL;
}
char *ft_strdup(char *str)
{
    char *new_str;
    size_t i;
    size_t size;
    if(!str)
    {
        return NULL;
    }

    i = 0;
    size = ft_strlen(str);
    new_str = malloc(size + 1);
    if(!new_str)
    {
        return (NULL);
    }
    while (str[i])
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}
char *ft_strjoin(char *str1, char *str2)
{
    size_t str1_len;
    size_t str2_len;
    char *new_str;
    int i;
    int j;
    size_t len_new;
    if (!str1 || !str2)
    {
        return NULL;
    }

    str1_len = ft_strlen(str1);
    str2_len = ft_strlen(str2);
    i = 0;
    j = 0;
    len_new = str1_len + str2_len + 1;
    new_str = malloc(len_new);
    if (!new_str)
    {
        return NULL;
    }
    while (str1[i])
    {
        new_str[i] = str1[i];
        i++;
    }
    while (str2[j])
    {
        new_str[i] = str2[j];
        j++;
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}