// C (no pointers) Practicum
// SWEN-250
// Larry Kiser October 3, 2024

#include <stdlib.h>
#include <stdio.h>
#include "cpracticum1.h"
#include "unit_tests.h"

// This function is implemented incorrectly. You need to correct it.
// It is supposed to total up the integers in the array for the number of entries in the
// second parameter.
// It returns that sum.
// If entry_count is 0 this function must return a 0.
// NOTE -- you are required to correct this code. You are not allowed to completely rewrite it.
// NOTE -- passing all unit tests does *not* guarantee that your code is correct.

int fix_bad_code( int numbers[], int entry_count )
{
    int i ; // declared as 0 later
    int total = 0; // start at 0 to ensure fair sum
    int result ; // needed if entry count is 0, just in case

    for ( i = 0 ; i < entry_count ; i++){
        total = total + numbers[i] ;
	}

	
    if (entry_count == 0)	// checking if entry count is 0, to ensure it returns a 0
	result = 0;

    else
	    result = total;


   
    return result;
}

// Copy of the typedef struct from cpracticum1.h for your convenience:
// struct typedef
// typedef struct
// {   
//    int length ;                // number of characters in the string not including end of string marker
//    int number_of_digits ;      // count of digits '0' through '9'.
// } string_info_t ;

// Returns some statistics for the passed string in the mystring array.
// Count the number of characters in the string and store that in length.
// Count the number of digits from '0' through '9' and store that in number_of_digits.
// Returns the string_info_t with these two members filled in correctly.
// NOTE -- you are *not* allowed to use any string functions like strlen and isdigit.
// 
// Examples: get_info( "1 2" ) ;	// length is 3 and number of digits is 2
// Examples: get_info( "" ) ;		// length is 0 and number of digits is 0
string_info_t get_info( char mystring[] )
{
	string_info_t info = { -1, -1 } ;	// initialized to bad values, modify to correct ones at the end
	int total = 0; // length
	int num_total = 0; // if its a number
	int cur; // NOTE FOR REST OF TEST PLEASE READ!!! : cur will be my definition for the current character variable
	int i = 0;
	cur = mystring[i]; // set it to a value that is not the end of array value
	while (cur != '\0'){
		if (cur >= 48 && cur <= 57){
			num_total ++; // add num if its the ascii values 0 - 9
		}
		total ++;
		i++;
		cur = mystring[i];
	}	
	info.length = total;
	info.number_of_digits = num_total;
	return info ;
}

// Replace every comma in mystring with a space character.
// Return the number of spaces in the updated mystring array.
// Return 0 if mystring is an empty string.
// You may not use functions like isalpha or strlen or isspace.
int replace_commas( char mystring[] )
{
	int i = 0;
	int cur = mystring[i];
	int total = 0;
	while (cur != '\0'){
		if (cur == 44){
			mystring[i] = 32; // ASCII for white space
			total ++; //increment
		}
		i++;// increment
		cur = mystring[i];//progress through string
	}
	return total ;      // cause unit tests to fail -- remove or comment out before submitting.
}


// Return the character that is at the passed position in the mystring array.
// NOTE -- position MAY be past the end of the mystring array.
//         YOU MUST check this before returning a character.
// If the position is past the end of the array return '?' -- do not go past the end!
// You may not use functions like isalpha or strlen or isspace.
char get_char_at_position( char mystring[], int position )
{
	int length = 0;
	int cur = mystring[length];
	while (cur != '\0'){
		length ++;
		cur = mystring[length];
	}
	if (position < length && position >= 0)
		return mystring[position];
	else{
	return '?';
	}
}
/*
 * notes for self: if string is "1 h 3" then length is 5 if position is 
 */

// Run the unit tests only
int main( int argc, char *argv[] ) {

    return test() ;
}
