// C (no pointers) Practicum
// SWEN-250
// Larry Kiser October 2, 2024

// struct typedef
typedef struct
{
    int length ;				// number of characters in the string not including end of string marker
    int number_of_digits ;		// count of digits '0' through '9'.
} string_info_t ;

// Function prototypes
int fix_bad_code( int numbers[], int entry_count ) ;
string_info_t get_info( char mystring[] ) ;
int replace_commas( char mystring[] ) ;
char get_char_at_position( char mystring[], int position ) ;
