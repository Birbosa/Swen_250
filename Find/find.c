/*
 * Implementation of functions that find values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h>
 *****
 */

#include <stdlib.h>
#include <stdbool.h>

#include "find.h"

#define NOT_FOUND (-1)	// integer indicator for not found.

/*
 * Return the index of the first occurrence of <ch> in <string>,
 * or (-1) if the <ch> is not in <string>.
 */
int find_ch_index(char string[], char ch) {
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ch) {
            return i;
        }
    }
    return NOT_FOUND; // Not found
}


/*
 * Return a pointer to the first occurrence of <ch> in <string>,
 * or NULL if the <ch> is not in <string>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_ch_ptr(char *string, char ch) {
    while (*string != '\0') {
        if (*string == ch) {
            return string;
        }
        ++string;
    }
    return NULL; // Not found
}


/*
 * Return the index of the first occurrence of any character in <stop>
 * in the given <string>, or (-1) if the <string> contains no character
 * in <stop>.
 */
int find_any_index(char string[], char stop[]) {
    for (int i = 0; string[i] != '\0'; ++i) {
        for (int j = 0; stop[j] != '\0'; ++j) {
            if (string[i] == stop[j]) {
                return i;
            }
        }
    }
    return NOT_FOUND; // Not found
}


/*
 * Return a pointer to the first occurrence of any character in <stop>
 * in the given <string> or NULL if the <string> contains no characters
 * in <stop>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_any_ptr(char *string, char *stop) {
    for (; *string != '\0'; ++string) {
        for (char *s = stop; *s != '\0'; ++s) {
            if (*string == *s) {
                return string;
            }
        }
    }
    return NULL; // Not found
}


/*
 * Return a pointer to the first character of the first occurrence of
 * <substr> in the given <string> or NULL if <substr> is not a substring
 * of <string>.
 * Note: An empty <substr> ("") matches *any* <string> at the <string>'s
 * start.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_substr(char *string, char *substr) {
    if (*substr == '\0') { // Empty substring matches at the start
        return string;
    }
    char *s, *sub;
    while (*string != '\0') {
        s = string;
        sub = substr;
        while (*s != '\0' && *sub != '\0' && *s == *sub) {
            ++s;
            ++sub;
        }
        if (*sub == '\0') { // Found the substring
            return string;
        }
        ++string;
    }
    return NULL; // Not found
}

