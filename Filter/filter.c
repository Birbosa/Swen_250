/*
 * Implementation of functions that filter values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h> OTHER THAN
 * strcpy() and strlen()
 *****
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "filter.h"

#define NUL ('\0')

/*
 * YOU MAY FIND THIS FUNCTION USEFUL.
 * Return true if and only if character <c> is in string <s>.
 */
static bool includes(char c, char *s) {
	while( *s && c != *s ) {
		s++ ;
	}
	return c == *s ;
}

/*
 * YOU MAY ALSO FIND THIS FUNCTION USEFUL.
 * Return true if and only if string <pre> is a prefix of string <s>.
 */
static bool prefix(char *s, char *pre) {
	while( *pre && *s == *pre ) {
		s++ ;
		pre++ ;
	}
	return *pre == NUL ;
}

/*
 * Copy <string> to <result> while removing all occurrences of <ch>.
 */
void filter_ch_index(char string[], char result[], char ch) {
    char *src = string;
    char *dst = result;
    
    while (*src) {
        if (*src != ch) {
            *dst = *src;  // copy character if it's not the one to remove
            dst++;  // move the destination pointer forward
        }
        src++;  // move the source pointer forward
    }
    *dst = NUL;  // terminate the result string
}


/*
 * Return a pointer to a string that is a copy of <string> with
 * all occurrences of <ch> removed. The returned string must occupy
 * the least possible dynamically allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_ch_ptr(char *string, char ch) {
    char *src = string;
    char *result = malloc(1);  // initially allocate memory for the null terminator
    char *dst = result;  // pointer to result (start at the beginning)

    while (*src) {
        if (*src != ch) {
            result = realloc(result, (dst - result + 2) * sizeof(char));  // increase memory size for next character
            *dst = *src;
            dst++;  // move the destination pointer forward
        }
        src++;  // move the source pointer forward
    }

    *dst = NUL;  // terminate the result string
    return result;
}


/*
 * Copy <string> to <result> while removing all occurrences of
 * any characters in <remove>.
 */
void filter_any_index(char string[], char result[], char remove[]) {
    char *src = string;
    char *dst = result;

    while (*src) {
        bool found = false;
        char *r = remove;
        while (*r) {
            if (*src == *r) {
                found = true;
                break;
            }
            r++;
        }
        if (!found) {
            *dst = *src;  // copy character if it's not in the remove string
            dst++;  // move the destination pointer forward
        }
        src++;  // move the source pointer forward
    }
    *dst = NUL;  // terminate the result string
}


/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of any characters in <remove>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_any_ptr(char *string, char* remove) {
    char *src = string;
    char *result = malloc(1);  // initially allocate memory for the null terminator
    char *dst = result;

    while (*src) {
        bool found = false;
        char *r = remove;
        while (*r) {
            if (*src == *r) {
                found = true;
                break;
            }
            r++;
        }
        if (!found) {
            result = realloc(result, (dst - result + 2) * sizeof(char));  // resize memory
            *dst = *src;
            dst++;  // move the destination pointer forward
        }
        src++;  // move the source pointer forward
    }

    *dst = NUL;  // terminate the result string
    return result;
}


/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of the substring <substr>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE ARRAY INDEXING.
 *****
 */
char *filter_substr(char *string, char* substr) {
    char *src = string;
    char *result = malloc(1);  // initially allocate memory for the null terminator
    char *dst = result;

    while (*src) {
        // Check if current position in string matches substr
        if (prefix(src, substr)) {
            // Skip ahead by length of substr
            src += strlen(substr);  // we can use strlen since it doesn't involve array indexing
        } else {
            result = realloc(result, (dst - result + 2) * sizeof(char));  // resize memory
            *dst = *src;
            dst++;  // move the destination pointer forward
            src++;  // move the source pointer forward
        }
    }

    *dst = NUL;  // terminate the result string
    return result;
}

