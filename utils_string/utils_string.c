/**
 * @file utils_string.c
 * @brief String manipulation and parsing utilities implementation
 * @author Mahmoud Mohamed Youness
 * @date Dec 26, 2025
 */

/*===========================================================================*/
/* Includes                                                                  */
/*===========================================================================*/
#include "utils_string.h"

/*===========================================================================*/
/* Public Function Implementations                                           */
/*===========================================================================*/

size_t strcpy_safe(char *dest, const char *src, size_t dest_size)
{
    if (dest == NULL || src == NULL || dest_size == 0)
    {
        return 0;
    }

    size_t i;
    for (i = 0; i < dest_size - 1 && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return i;
}

size_t strcat_safe(char *dest, const char *src, size_t dest_size)
{
    if (dest == NULL || src == NULL || dest_size == 0)
    {
        return 0;
    }

    size_t dest_len = strlen_safe(dest, dest_size);
    size_t i;

    for (i = 0; dest_len + i < dest_size - 1 && src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest_len + i;
}

int strcmp_safe(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return (s1 == s2) ? 0 : (s1 == NULL ? -1 : 1);
    }

    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

int stricmp_safe(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return (s1 == s2) ? 0 : (s1 == NULL ? -1 : 1);
    }

    while (*s1 && *s2)
    {
        char c1 = (*s1 >= 'A' && *s1 <= 'Z') ? *s1 + 32 : *s1;
        char c2 = (*s2 >= 'A' && *s2 <= 'Z') ? *s2 + 32 : *s2;

        if (c1 != c2)
        {
            return c1 - c2;
        }
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int strncmp_safe(const char *s1, const char *s2, size_t n)
{
    if (s1 == NULL || s2 == NULL || n == 0)
    {
        return 0;
    }

    while (n > 0 && *s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
        n--;
    }

    return (n == 0) ? 0 : (*(unsigned char*)s1 - *(unsigned char*)s2);
}

size_t strlen_safe(const char *str, size_t max_len)
{
    if (str == NULL)
    {
        return 0;
    }

    size_t len = 0;
    while (len < max_len && str[len] != '\0')
    {
        len++;
    }

    return len;
}

char* strchr_safe(const char *str, char ch)
{
    if (str == NULL)
    {
        return NULL;
    }

    while (*str != '\0')
    {
        if (*str == ch)
        {
            return (char*)str;
        }
        str++;
    }

    return NULL;
}

char* strstr_safe(const char *str, const char *substr)
{
    if (str == NULL || substr == NULL || *substr == '\0')
    {
        return NULL;
    }

    while (*str != '\0')
    {
        const char *s1 = str;
        const char *s2 = substr;

        while (*s1 && *s2 && (*s1 == *s2))
        {
            s1++;
            s2++;
        }

        if (*s2 == '\0')
        {
            return (char*)str;
        }

        str++;
    }

    return NULL;
}

char* strtriml_safe(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    while (strisspace_safe(*str))
    {
        str++;
    }

    return str;
}

char* strtrimr_safe(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    char *end = str + strlen_safe(str, 1024) - 1;

    while (end > str && strisspace_safe(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char* strtrim_safe(char *str)
{
    str = strtriml_safe(str);
    return strtrimr_safe(str);
}

size_t strtok_safe(char *str, char delim, str_token_result_t *result)
{
    if (str == NULL || result == NULL)
    {
        return 0;
    }

    result->count = 0;
    char *token = str;
    _Bool in_token = false;

    while (*str != '\0' && result->count < STR_MAX_TOKENS)
    {
        if (*str == delim)
        {
            *str = '\0';
            if (in_token)
            {
                result->tokens[result->count++] = token;
                in_token = false;
            }
            token = str + 1;
        }
        else if (!in_token)
        {
            in_token = true;
        }
        str++;
    }

    if (in_token && result->count < STR_MAX_TOKENS)
    {
        result->tokens[result->count++] = token;
    }

    return result->count;
}

_Bool strstarts_safe(const char *str, const char *prefix)
{
    if (str == NULL || prefix == NULL)
    {
        return false;
    }

    while (*prefix != '\0')
    {
        if (*str != *prefix)
        {
            return false;
        }
        str++;
        prefix++;
    }

    return true;
}

_Bool strends_safe(const char *str, const char *suffix)
{
    if (str == NULL || suffix == NULL)
    {
        return false;
    }

    size_t str_len = strlen_safe(str, 1024);
    size_t suffix_len = strlen_safe(suffix, 1024);

    if (suffix_len > str_len)
    {
        return false;
    }

    return strcmp_safe(str + str_len - suffix_len, suffix) == 0;
}

void strupper_safe(char *str) {
    if (str == NULL) {
        return;
    }

    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }
}

void strlower_safe(char *str)
{
    if (str == NULL)
    {
        return;
    }

    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str + 32;
        }
        str++;
    }
}

_Bool strisspace_safe(char ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\v' || ch == '\f');
}

_Bool strisdigit_safe(char ch)
{
    return (ch >= '0' && ch <= '9');
}

_Bool strisalpha_safe(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
