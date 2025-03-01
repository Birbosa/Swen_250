/*
 * Skeleton implementation for the activity to parse and print
 * CSV formatted files read from standard input.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csv.h"
#include "unit_tests.h"


/*
 * Returns true iff the character 'ch' ends a field. That is, ch is end of file,
 * a comma, or a newline.
 */

bool is_end_of_field(int ch) {
	return (ch == ',') || (ch == '\n') || (ch == EOF) || (ch == '\r') ;
}

/*
 * Return the minimum of two integers.
 */

int min(int x, int y) {
	return x < y ? x : y ;
}

/*
 * Read the next field from standard input. Returns the value of getchar() that
 * stopped (terminated) the field.
 */

int get_field(f_string field) {
	/* FILL THIS IN */
	int cur = '\0';
	int i = 0;

	while ((cur = getchar()) != EOF && !is_end_of_field(cur)) {
		if (i < MAX_CHARS) {
			field [i++] = cur;
		}
	}

	field[i] = '\0';

	return cur;

}

/*
 * Read in a CSV line. No error checking is done on the number of fields or
 * the size of any one field.
 * On return, the fields have been filled in (and properly NUL-terminated), and
 * nfields is the count of the number of valid fields.
 * nfields == 0 means end of file was encountered.
 */

csv_line get_line() {
    csv_line line;
    int ch;
    line.nfields = 0;

    // Read fields until we reach newline, EOF, or max field count
    while (line.nfields < MAX_FIELDS) {
        ch = get_field(line.field[line.nfields]);

        // Increment the number of fields
        line.nfields++;

        // Stop if newline or EOF is encountered
        if (ch == '\n' || ch == EOF) {
            break;
        }
    }

    // Reset nfields to 0 if EOF is reached at the start
    if (ch == EOF && line.nfields == 1 && line.field[0][0] == '\0') {
        line.nfields = 0;
    }

    return line;
}

/*
 * Print a CSV line, associating the header fields with the
 * data line fields.
 * The minimum of the number of fields in the header and the data
 * determines how many fields are printed.
 */

void print_csv(csv_line header, csv_line data) {
    int fields_to_print = min(header.nfields, data.nfields);

    for (int i = 0; i < fields_to_print; i++) {
        printf("%s: %s\n", header.field[i], data.field[i]);
    }

    // Debug output to check unexpected behavior
    fprintf(stderr, "DEBUG: header.nfields=%d, data.nfields=%d\n", header.nfields, data.nfields);

    // Add a blank line between rows for readability
    printf("\n");
}



/*
 * Driver - read a CSV line for the header then read and print data lines
 * until end of file.
 */

int main( int argc, char *argv[] ) {
	csv_line header ;
	csv_line current ;

	// LLK additional if statement to execute unit tests if program
	// name contains "test".
	if ( strstr( argv[0], "test" ) )
		return test() ;

	header = get_line() ;
	current = get_line() ;

	while ( current.nfields > 0 ) {
		print_csv(header, current) ;
		current = get_line() ;
	}

	return 0 ;
}
