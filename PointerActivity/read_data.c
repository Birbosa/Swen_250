/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "read_data.h"

void read_data(char *c, int *i, double *d) {
    char input[100];  // Buffer to store the input line
    char *token;      // Token for parsing the string

    // Read the input line (assuming input is properly formatted)
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }

    // Parse the character field (first token before the first $)
    token = strtok(input, "$");
    if (token != NULL) {
        *c = token[0];  // Store the first character in *c
    }

    // Parse the integer field (second token)
    token = strtok(NULL, "$");
    if (token != NULL) {
        *i = atoi(token);  // Convert to integer and store in *i
    }

    // Parse the double field (third token)
    token = strtok(NULL, "$");
    if (token != NULL) {
        *d = atof(token);  // Convert to double and store in *d
    }
}
