// unit_tests student additions
// Larry L. Kiser Oct. 22, 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "analysis.h"
#include "unit_tests_analysis.h"
#include "unit_tests.h"

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
// returns the number of failed tests.
int test_student()
{
    int passcount = 0 ;
    int failcount = 0 ;
    struct linked_list list1 ;       // list list pointers for one list
    
    // Initialize local stack data
    memset( &list1, 0, sizeof( list1 ) ) ;        // set all pointers to NULL (zero)
    
    printf( "\n========= student generated tests on MLK excerpt ===============================\n" ) ;
    int result = read_file( &list1, "MLK_dream_excerpt.txt" ) ;
    assert( result == 113,
        "1 read_file processing MLK_dream_excerpt. Expect word count of 113 returned but got %d.", result )
        ? passcount++ : failcount++ ;

    // Add a test to verify that the word "day" is used three times in the list.
    int day_count = 0;
    struct word_entry entry = get_first_entry(&list1);
    do {
        if (entry.unique_word != NULL) {
            if (strcmp(entry.unique_word, "day") == 0) {
                day_count = entry.word_count;
            }
        }
        entry = get_next_entry(&list1);
    } while (entry.unique_word != NULL);
    
    assert(day_count == 3, "The word 'day' should appear 3 times in the list but found %d times.", day_count)
        ? passcount++ : failcount++ ;

    // Add a test to verify that the word AFTER the word "have" is the word "heat".
    int have_found = 0;
    char *next_word = NULL;
    entry = get_first_entry(&list1);
    do {
        if (strcmp(entry.unique_word, "have") == 0) {
            have_found = 1;
            entry = get_next_entry(&list1); // Get next word after "have"
            next_word = entry.unique_word;
            break;
        }
        entry = get_next_entry(&list1);
    } while (entry.unique_word != NULL);
    
    assert(have_found == 1 && strcmp(next_word, "heat") == 0, 
           "The word after 'have' should be 'heat', but got '%s'.", next_word)
        ? passcount++ : failcount++ ;

    // Add a test to verify that the last word in the list is "with"
    entry = get_last_entry(&list1);
    assert(entry.unique_word != NULL && strcmp(entry.unique_word, "with") == 0, 
           "The last word should be 'with', but got '%s'.", entry.unique_word)
        ? passcount++ : failcount++ ;

    // Add a test to verify that the next to the last word is "will"
    entry = get_prev_entry(&list1); // Move to the second last entry
    assert(entry.unique_word != NULL && strcmp(entry.unique_word, "will") == 0, 
           "The second last word should be 'will', but got '%s'.", entry.unique_word)
        ? passcount++ : failcount++ ;

    result = clear_linked_list( &list1 ) ;
    assert( result == 62,
        "6 clear linked list expected to remove 62 entries but got %d.", result )
        ? passcount++ : failcount++ ;

    printf( "\nSummary of analysis unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
    
    return failcount ;
}
