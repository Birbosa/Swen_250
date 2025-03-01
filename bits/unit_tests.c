// unit_tests.c
// Larry Kiser December 5, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "bits.h"
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
int test()
{
	int passcount = 0 ;
	int failcount = 0 ;
	unsigned int value = 0 ;
	
	printf( "\n----------------- testing shift_value ------------------------------------------\n" ) ;
	// Test 1 -- 
	value = 1 ;
	shift_value( &value, 1 ) ;
	assert( value == 2,
		" 1 Expected 2 but got %d", value )
		? passcount++ : failcount++ ;
		
	// Test 2 -- 
	value = 0x40 ;
	shift_value( &value, 1 ) ;
	assert( value == 0x80,
		" 2 Expected 0x80 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 3 -- 
	value = 0x20 ;
	shift_value( &value, 4 ) ;
	assert( value == 0x200,
		" 3 Expected 0x200 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 4 -- 
	value = 0x20 ;
	shift_value( &value, 4 ) ;
	assert( value == 0x200,
		" 4 Expected 0x200 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 5 -- 
	value = 0x20 ;
	shift_value( &value, -4 ) ;
	assert( value == 0x2,
		" 5 Expected 0x2 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
		
	// Test 6 -- 
	value = 0x20 ;
	shift_value( &value, 0 ) ;
	assert( value == 0x20,
		" 6 Expected 0x20 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	printf( "\n----------------- testing set_bit -----------------------------------------------\n" ) ;
	// Test 7 --
	value = 0x20 ;
	set_bit( &value, 0 ) ;
	assert( value == 0x21,
		" 7 Expected 0x21 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 8 --
	value = 0x07 ;
	set_bit( &value, 1 ) ;
	assert( value == 0x07,
		" 8 Expected 0x07 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 9 --
	value = 0x07 ;
	set_bit( &value, 3 ) ;
	assert( value == 0x0f,
		" 9 Expected 0xff but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 10 --
	value = 0x00 ;
	set_bit( &value, 31 ) ;
	assert( value == 0x80000000,
		" 10 Expected 0x80000000 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	printf( "\n----------------- testing flip_all ----------------------------------------------\n" ) ;

	// Test 11 --
	value = 0x00 ;
	flip_all( &value ) ;
	assert( value == 0xffffffff,
		" 11 Expected 0xffffffff but got 0x%x", value )
		? passcount++ : failcount++ ;

	// Test 12 -- 
	value = 0x10203040 ;
	flip_all( &value ) ;
	assert( value == 0xefdfcfbf,
		" 12 Expected 0xefdfcfbf but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 13 -- 
	value = 0xffffffff ;
	flip_all( &value ) ;
	assert( value == 0x0,
		" 13 Expected 0x0 but got 0x%x", value )
		? passcount++ : failcount++ ;

	printf( "\n----------------- testing clear_bit ---------------------------------------------\n" ) ;
		
	// Test 14 -- 
	value = 0xffffffff ;
	clear_bit( &value, 0 ) ;
	assert( value == 0xfffffffe,
		" 14 Expected 0xfffffffe but got 0x%x", value )
		? passcount++ : failcount++ ;

	// Test 15 -- 
	value = 0xffffffff ;
	clear_bit( &value, 30 ) ;
	assert( value == 0xbfffffff,
		" 15 Expected 0xbffffffe but got 0x%x", value )
		? passcount++ : failcount++ ;
		
	// Test 16 -- 
	value = 0x00000001 ;
	clear_bit( &value, 1 ) ;
	assert( value == 0x00000001,
		" 16 Expected 0x00000001 but got 0x%x", value )
		? passcount++ : failcount++ ;
		
		
	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}
