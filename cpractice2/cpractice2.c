// C pointers light Practice Practicum Solution
// SWEN-250
// Larry Kiser November 29, 2015

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpractice2.h"
#include "unit_tests.h"

// return a pointer to the character that is at the passed position.
// return a null if the requested position is past the end of the string.
// Hint -- to solve this you need to do some simple pointer math. You are allowed to use string functions.
// Parameters:
//      *pstring is a character pointer to a typical string.
//      position is zero based index into the string/
char *get_pointer_at_position( char *pstring, int position )
{
	char *pres = NULL;
	int length = strlen(pstring);// can use string funcs

	if ( position < length)
		pres = pstring + position;
	return pres;
	


	

	

}


// Convert array of integer x values into an array of y values using y = mx + b where m and b are constants
// passed to the function.
// You must return an array of y values. This array must be stored on the heap. This array must be
// exactly the right size to store the y_values!
// Only create this array of y values if you have a valid px pointer and valid number_of_x_values
//     as described below.
// You must not modify the array of x values.
// The m and b integer constants can be positive, negative or zero.
// Return NULL if the passed in px pointer is NULL or if the number_of_x_values is <= 0.
// Parameters:
//      *px is a pointer to an array of x values.
//      m is the integer slope
//      b is the integer offset.
//      number_of_x_values is the number of entries in the array of x values

#define BAD_POINTER (int *)1	// create a bogus pointer for unit testing
int *get_y_values( int *px, int m, int b, int number_of_x_values )
{
	int *p_y_vals = NULL;
	int *p_loader = NULL;

	if (px && number_of_x_values > 0)
	{
		//gonna be long so use brackets
		p_y_vals = malloc (sizeof(int) * number_of_x_values);
		p_loader = p_y_vals;
		while (number_of_x_values-- > 0)
			*p_loader++ = (*px++ * m) + b; //slope formula
	}


	return p_y_vals;
}


// Adds up the number of integers in the passed py array.
// The number of integers is in number_of_y_values.
// If py is a NULL pointer you must return 0.
// If py is BAD_POINTER you must return 0.
// If number_of_y_values is <= 0 you must return 0.
// If the number_of_y_values is > 0 the passed pointer py is space that was allocated on the
// heap. You must free this space if and only if the number_of_y_values is > 0.
int get_sum_and_free_space( int *py, int number_of_y_values )
{
	int sumed = 0;
	int *p_work = py; // i forgot to use another pointer, hence late correction
	if (py && number_of_y_values > 0)
	{
		while (number_of_y_values--) // auto fail on 0
		       sumed += *p_work++;
		free (py);	
	}
	return sumed;
}


// Determine if two pointers point to the same array of numbers
// return 1 if they do, return 0 otherwise.
// return 0 if either pointer is NULL.
int same_array( int *pfirst, int *psecond )
{
	if (pfirst == NULL || psecond == NULL)
		return 0;

	if ( pfirst == psecond )
		return 1;
	else
		return 0;
}

// The first time this is called return 1.
// The second time this is called return 0.
// Continue this pattern returning 1, then 0, then 1 and so on.
int bool_flip_flop()
{
	static int flip_flop = 0;
	
	if (flip_flop)
		flip_flop = 0;
	else
		flip_flop = 1;
	return flip_flop; // fliped the flop a ya


}

// This function is implemented incorrectly. You need to correct it.
// When fixed it changes the last character in the passed string to 'Z'.
// It returns returns 1 on success.
// It returns 0 on if the passed string is NULL or an empty string.
int fix_bad_code( char *pstring )
{
    if (pstring == NULL || *pstring == '\0')
        return 0 ;
    while ( !*pstring == '\0' )
	pstring = pstring + 1;
    	if (*pstring  == '\0'){
		pstring = pstring - 1;
		*pstring = 'Z';
		pstring = pstring +1;
	}
    return 1 ;
}
