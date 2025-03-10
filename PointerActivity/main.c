/*
 * Driver program for the activity.
 *  1. Declares local variables for the character, integer, and
 *     double precision values returned by read_data.
 *  2. Calls read_data with pointers to the variables so that
 *     the values read can be returned.
 *  3. On return, prints the character, integer, and double
 *     precision number using the following format string for
 *     printf:
 *         "Character %c Integer %d Floating point %.4f\\n"
 *     Note: you must also, of course, provide the values to
 *     be printed.
 *  4. Return a 0 to the operating system.
 */

#include <stdlib.h>
#include <stdio.h>
#include "read_data.h"

int main() {
    char c;
    int i;
    double d;

    // Call the read_data function
    read_data(&c, &i, &d);

    // Print the values returned by read_data
    printf("Character %c Integer %d Floating point %.4f\\n", c, i, d);

    return 0;
}
