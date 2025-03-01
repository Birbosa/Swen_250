// C pointers final practicum 
// SWEN-250 Fall 2024 Term 2241

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pfinal.h"
#include "unit_tests.h"

// Return a NULL pointer if start_letter is not 'a' through 'z'.
// Return a NULL pointer if the number_of_letters is less than or equal to zero.
//
// If both parameters are valid create a string containing 
// successive letters starting with the lower case start_letter.
// The length of the string is specified by number_of_letters.
//
// You are required to malloc exactly the smallest valid
// string to hold the letters. You return this string.
//
// If you get to 'z' and you still have letters to add wrap
// around to the letter 'a'.
// Examples:
// start_letter == 'c' ; number_of_letters == 5 ; string == "cdefg"
// start_letter == 'y' ; number_of_letters == 4 ; string == "yzab"
// return this string from this function
// 
// Parameters:
//		start_letter is a letter from 'a' through 'z' inclusive.
//		number_of_letters is how many letters are in the string you create.
char *make_string_of_letters( char start_letter, int number_of_letters )
{
	if (number_of_letters <= 0 || !islower(start_letter)) {
        return NULL;
    }

    char *ret_string = (char *)malloc(number_of_letters + 1); //num of letters + terminator at the minimum
    if (ret_string == NULL) {
        return NULL; // catch for the scenarios just in case
    }

    char cur = start_letter; // start
    for (int i = 0; i < number_of_letters; i++) {
        ret_string[i] = cur; //current value is current
        if (cur == 'z'){
            cur = 'a'; // reset if z
        }
        else{
            cur ++; //progress it
        }
    }
    ret_string[number_of_letters] = '\0'; //dont forget to add null terminator, otherwise error might occur

    return ret_string; // done
}


// Counts the number of letter grades in the passed array of integer grades.
// Returns 0 if the grade_count is <= 0.
// Returns 0 if p_status is a NULL pointer.
// Returns 0 if the p_grades pointer is NULL.
// Returns 1 if all three parameters are valid as described above.

// A grades are 90 through 100
// B grades are 80 through 89
// C grades are 70 through 79
// D grades are 60 through 69
// F grades are 0 through 59
// NOTE -- you can assume that all integer grades in the p_grades array  are 0 through 100.
// TIP -- initialize the p_status structure to have 0 counts.
int count_grades(int *p_grades, int grade_count, struct grade_stats *p_stats) {
    if (p_grades == NULL || p_stats == NULL || grade_count <= 0) {
        return 0; // 0 if not valid
    }

    // grades are set to 0 like said above
    p_stats->a_grades = 0;
    p_stats->b_grades = 0;
    p_stats->c_grades = 0;
    p_stats->d_grades = 0;
    p_stats->f_grades = 0;

    for (int i = 0; i < grade_count; i++) { // amount of grades to sleect from delcars loop length
        int grade = p_grades[i];

        if (grade >= 90) { // use chain of if, else if, else, to prevent multiple sections from being added
            p_stats->a_grades++; 
        } else if (grade >= 80) { // ^ else if but same
            p_stats->b_grades++;
        } else if (grade >= 70) { // ^ else if but same
            p_stats->c_grades++;
        } else if (grade >= 60) { // ^ else if but same
            p_stats->d_grades++;
        } else {
            p_stats->f_grades++; // if nothing catches, its an f
        }
    }

    return 1; // return 1 on sucess
}


// Search the p_input string for a number.
// If one is found convert it to an integer.
// Return that integer using the p_number_found.
// Return 1 from this function to indicate success.
// NOTE -- you can assume that p_input and p_number_found
//         are valid pointers!
//
// If no number is found return 0 from this function.
//
// You are allowed to use standard C string and conversion
// functions like atoi() and isdigit().
// Examples:
// "abdX8ZZ" return 8 and success
// "123" returns 123 and success
// "" returns failure
//
int extract_number( char *p_input, int *p_number_found ) 
{
	// things to note first:
    //atoi and isdigit are very likely to be used since they are mentioned above
    //similar to practicum 2 questions
    //atoi will only convert the numbers to numbers
    // digits will check to find if number are present to begin with, as atoi being used prematurely will cause errors
    char *ptr = p_input;
    while (*ptr != '\0'){ // see bellow and practicum 2 for reference as to why, but it just goes through it
        if (isdigit(*ptr)){//has a number been found?
            *p_number_found = atoi(ptr); // ints inside of string are put inside of number found
            return 1;
        }
        ptr++;// increment
}
	return 0 ;	
}


// This function is implemented incorrectly. You need to correct it.
// When fixed it returns 1 if there are any digits (0 through 9) anywhere in the passed string.
// If there are no digits it returns 0.
// It also returns 0 if the passed string pointer is NULL or if the string points to an empty string.
// You can re-write this code completely if you prefer.
int fix_bad_code( char *pstring )
{
    int result = 0; //by default
	if (pstring ) // not null, can also use pstring != NULL or !pstring == NULL
		while (*pstring != '\0') // is not empty or ended
			if (isdigit(*pstring++)) // check all digits
				result = 1; // assert as 1
	return result; // 0 or 1 depending on reslts
}

