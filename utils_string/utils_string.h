/**
 * @file utils_string.h
 * @brief String manipulation and parsing utilities
 * @author Mahmoud Mohamed Youness
 * @date Dec 26, 2025
 */

#ifndef UTILS_STRING_H
#define UTILS_STRING_H

/*===========================================================================*/
/* Includes                                                                  */
/*===========================================================================*/

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*===========================================================================*/
/* Macro Definitions                                                         */
/*===========================================================================*/

#define STR_MAX_TOKENS 10

/*===========================================================================*/
/* Type Definitions                                                          */
/*===========================================================================*/

typedef struct {
    char *tokens[STR_MAX_TOKENS];
    size_t count;
} str_token_result_t;

/*===========================================================================*/
/* Function Prototypes                                                       */
/*===========================================================================*/

/**
 * @brief Safe string copy with null termination guarantee
 * @param dest Destination buffer
 * @param src Source string
 * @param dest_size Size of destination buffer
 * @return Number of characters copied (excluding null terminator)
 */
size_t strcpy_safe(char *dest, const char *src, size_t dest_size);

/**
 * @brief Safe string concatenation
 * @param dest Destination buffer
 * @param src Source string to append
 * @param dest_size Size of destination buffer
 * @return Total length of string after concatenation
 */
size_t strcat_safe(char *dest, const char *src, size_t dest_size);

/**
 * @brief Compare two strings (case sensitive)
 * @param s1 First string
 * @param s2 Second string
 * @return 0 if equal, <0 if s1<s2, >0 if s1>s2
 */
int strcmp_safe(const char *s1, const char *s2);

/**
 * @brief Compare two strings (case insensitive)
 * @param s1 First string
 * @param s2 Second string
 * @return 0 if equal, <0 if s1<s2, >0 if s1>s2
 */
int stricmp_safe(const char *s1, const char *s2);

/**
 * @brief Compare first n characters of two strings
 * @param s1 First string
 * @param s2 Second string
 * @param n Number of characters to compare
 * @return 0 if equal, <0 if s1<s2, >0 if s1>s2
 */
int strncmp_safe(const char *s1, const char *s2, size_t n);

/**
 * @brief Get string length (safe version with max limit)
 * @param str String to measure
 * @param max_len Maximum length to check
 * @return Length of string or max_len if no null terminator found
 */
size_t strlen_safe(const char *str, size_t max_len);

/**
 * @brief Find character in string
 * @param str String to search
 * @param ch Character to find
 * @return Pointer to first occurrence or NULL if not found
 */
char* strchr_safe(const char *str, char ch);

/**
 * @brief Find substring in string
 * @param str String to search
 * @param substr Substring to find
 * @return Pointer to first occurrence or NULL if not found
 */
char* strstr_safe(const char *str, const char *substr);

/**
 * @brief Trim whitespace from start of string
 * @param str String to trim (modified in place)
 * @return Pointer to first non-whitespace character
 */
char* strtriml_safe(char *str);

/**
 * @brief Trim whitespace from end of string
 * @param str String to trim (modified in place)
 * @return Pointer to string (same as input)
 */
char* strtrimr_safe(char *str);

/**
 * @brief Trim whitespace from both ends of string
 * @param str String to trim (modified in place)
 * @return Pointer to trimmed string
 */
char* strtrim_safe(char *str);

/**
 * @brief Tokenize string by delimiter
 * @param str String to tokenize (will be modified)
 * @param delim Delimiter character
 * @param result Pointer to result structure
 * @return Number of tokens found
 */
size_t strtok_safe(char *str, char delim, str_token_result_t *result);

/**
 * @brief Check if string starts with prefix
 * @param str String to check
 * @param prefix Prefix to look for
 * @return true if string starts with prefix, false otherwise
 */
bool strstarts_safe(const char *str, const char *prefix);

/**
 * @brief Check if string ends with suffix
 * @param str String to check
 * @param suffix Suffix to look for
 * @return true if string ends with suffix, false otherwise
 */
bool strends_safe(const char *str, const char *suffix);

/**
 * @brief Convert string to uppercase (in place)
 * @param str String to convert
 */
void strupper_safe(char *str);

/**
 * @brief Convert string to lowercase (in place)
 * @param str String to convert
 */
void strlower_safe(char *str);

/**
 * @brief Check if character is whitespace
 * @param ch Character to check
 * @return true if whitespace, false otherwise
 */
bool strisspace_safe(char ch);

/**
 * @brief Check if character is digit
 * @param ch Character to check
 * @return true if digit (0-9), false otherwise
 */
bool strisdigit_safe(char ch);

/**
 * @brief Check if character is alphabetic
 * @param ch Character to check
 * @return true if alphabetic (a-z, A-Z), false otherwise
 */
bool strisalpha_safe(char ch);

#endif /* UTILS_STRING_H */
