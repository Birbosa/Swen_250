// C (no pointers) Practice Practicum
// SWEN-250
// Larry Kiser February 11, 2016

typedef struct
{
    int length;
    char myString[128];
} string_t;

// cpractice1 functions
int skip_spaces( char mystring[], int start_index ) ;
int find_next_word( char mystring[], int start_index ) ;
int change_to_upper( char mystring[], int index ) ;
int capitalize_all_words( char mystring[] ) ;
int fix_bad_code( int first, int second ) ;
string_t make_string_type(char input_string[]);

