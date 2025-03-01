// C pointers final practicum
// SWEN-250
// unit_tests

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "pfinal.h"
#include "unit_tests.h"

// Simple boolean assert function for unit testing
int assert( int test_result, char error_format[], ... ) {
	va_list arguments ;
	static int test_number = 1 ;
	int result = 1 ;	// return 1 for test passed or 0 if failed
	
	if ( ! test_result ) {
		va_start( arguments, error_format ) ;
		printf( "Test # %d failed: ", test_number ) ;
		vprintf( error_format, arguments ) ;
		printf( "\n" ) ;
		result = 0 ;
	}
	test_number++ ;
	return result ;
}

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
int test( int all )	// if all is true do the free unit tests at the end
{
	int passcount = 0 ;
	int failcount = 0 ;
	
	printf( "\nTests for make_string_of_letters....................\n" ) ;

	// Test 1
	assert( make_string_of_letters( 'B', 5 )  == NULL,
		"Expected NULL because start_letter is B (not a through z)" )
		? passcount++ : failcount++ ;

	// Test 2 
	assert( make_string_of_letters( 'd', 0 ) == NULL,
		"Expected NULL because number_of_letters is 0" )
		? passcount++ : failcount++ ;

	// Test 3 
	assert( make_string_of_letters( 'd', -1 ) == NULL,
		"Expected NULL because number_of_letters is -1" )
		? passcount++ : failcount++ ;

	// Test 4
	char *ptest4 = make_string_of_letters( 'f', 1 ) ;
	int good_pointer4 = ( ptest4 != NULL && ptest4 != BOGUS_POINTER ) ;
	assert( good_pointer4,
		"Expected valid pointer for string with just f but but it is NULL or BOGUS_POINTER" )
		? passcount++ : failcount++ ;

	// Test 5 
	if ( ! good_pointer4 )
	{
		assert( 0,
			 "Skipping test 5 due to bad pointer from test 4" ) ;
		failcount++ ;
	}
	else
		assert( strcmp( ptest4, "f" ) == 0,
			"Expected \"f\" but got \"%s\"", ptest4 )
		? passcount++ : failcount++ ;

	// Test 6
	char *ptest6 = make_string_of_letters( 'u', 7 ) ;
	int good_pointer6 = ( ptest6 != NULL && ptest6 != BOGUS_POINTER ) ;
	assert( good_pointer6,
		"Expected valid pointer for string with uvwxyza but but it is NULL or BOGUS_POINTER" )
		? passcount++ : failcount++ ;

	// Test 7 
	if ( ! good_pointer6 )
	{
		assert( 0,
			 "Skipping test 7 due to bad pointer from test 6" ) ;
		failcount++ ;
	}
	else
		assert( strcmp( ptest6, "uvwxyza" ) == 0,
			"Expected \"uvwxyza\" but got \"%s\"", ptest6 )
		? passcount++ : failcount++ ;
	
	printf( "\nTests for count_grades..............................\n" ) ;
	
	// Test 8
	struct grade_stats stat1 = { 1,2,8,4,5 } ;
	int grades[] = { 0, 59, 60, 69, 70, 71, 79, 80, 81, 82, 89, 90, 91, 92, 100 } ;
	int grade_count = sizeof( grades ) / sizeof( int ) ;

	assert( count_grades( NULL, 1,  &stat1 ) == 0,
		"Expect 0 since the grades pointer is NULL" )
		? passcount++ : failcount++ ;
	// Test 9
	assert( count_grades( grades, 0, &stat1 ) == 0,
		"Expect 0 since the grade count is 0" )
		? passcount++ : failcount++ ;
	// Test 10
	assert( count_grades( grades, grade_count, NULL ) == 0,
		"Expect 0 since the grade status pointer is NULL" )
		? passcount++ : failcount++ ;
	// Test 11
	assert( count_grades( grades, grade_count, &stat1 ) == 1,
		"Expect 1 because all three parameters are valid" )
		? passcount++ : failcount++ ;
	// Test 12
	assert( stat1.a_grades == 4 ,
		"Expect a_grades = 4 but got %d", stat1.a_grades )
		? passcount++ : failcount++ ;
	// Test 13
	assert( stat1.b_grades == 4 ,
		"Expect b_grades = 4 but got %d", stat1.b_grades )
		? passcount++ : failcount++ ;
	// Test 14
	assert( stat1.c_grades == 3 ,
		"Expect c_grades = 3 but got %d", stat1.c_grades )
		? passcount++ : failcount++ ;
	// Test 15
	assert( stat1.d_grades == 2 ,
		"Expect d_grades = 2 but got %d", stat1.d_grades )
		? passcount++ : failcount++ ;
	// Test 16
	assert( stat1.f_grades == 2 ,
		"Expect f_grades = 2 but got %d", stat1.f_grades )
		? passcount++ : failcount++ ;

	printf( "\nTests for extract_number............................\n" ) ;
	// Test 17
	int number_found = 0 ;

	assert( extract_number( "", &number_found ) == 0,
		"Expect 0 return value because input string is an empty string" )
		? passcount++ : failcount++ ;
	// Test 18
	assert( extract_number( "abcdefg", &number_found ) == 0,
		"Expect 0 return value because input string abcdefg has no numbers" )
		? passcount++ : failcount++ ;
	// Test 19"
	assert( extract_number( "1234", &number_found ) == 1,
		"Expect 1 return value because input string 1234 is a valid number" )
		? passcount++ : failcount++ ;
	// Test 20
	assert( number_found == 1234,
		"Expect number_found to be 1234 but got %d", number_found )
		? passcount++ : failcount++ ;
	// Test 21
	assert( extract_number( "abcd555", &number_found ) == 1,
		"Expect 1 return value because input string abcd555 has a valid number" )
		? passcount++ : failcount++ ;
	// Test 22
	assert( number_found == 555,
		"Expect number_found to be 555 but got %d", number_found )
		? passcount++ : failcount++ ;
	// Test 23
	assert( extract_number( "ABC9DEF", &number_found ) == 1,
		"Expect 1 return value because input string ABC9DEF has a valid number" )
		? passcount++ : failcount++ ;
	// Test 24
	assert( number_found == 9,
		"Expect number_found to be 9 but got %d", number_found )
		? passcount++ : failcount++ ;

    printf( "\nTests for fix_bad_code..............................\n" ) ;
    // Test 25
	int result = 0 ;
    result = fix_bad_code( "test" ) ;
    assert( result == 0,
        "Expected 0 because there are no digits but got %d",  result )
        ? passcount++ : failcount++ ;
    // Test 26
    result = fix_bad_code( "test1" ) ;
    assert( result == 1,
        "Expected 1 because there is one digit but got %d",  result )
        ? passcount++ : failcount++ ;
    // Test 27
    result = fix_bad_code( "" ) ;
    assert( result == 0,
        "Expected 0 because it is an empty string but got %d",  result )
        ? passcount++ : failcount++ ;
    // Test 28
    result = fix_bad_code( NULL ) ;
    assert( result == 0,
        "Expected 0 because the string pointer is a null pointer but got %d",  result )
        ? passcount++ : failcount++ ;


	if ( all )
	{
		printf( "\nNow freeing pointers created during prior unit tests\n" ) ;

		if ( good_pointer4 )
		{
			free( ptest4 ) ;	// free valid malloc from Test 4
			passcount++ ;
			printf( "\nfree of Test 4 pointer successful" ) ;
		}
		else
			printf( "\nSkipped free of Test 4 pointer: bad pointer from Test 4" ) ;

		if ( good_pointer6 )
		{
			free( ptest6 ) ;	// free valid malloc from Test 6
			passcount++ ;
			printf( "\nfree of Test 6 pointer successful" ) ;
		}
		else
			printf( "\nSkipped free of Test 6 pointer: bad pointer from Test 6" ) ;
	}

	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}
