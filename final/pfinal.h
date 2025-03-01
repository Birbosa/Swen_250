// C pointers final Practicum
// SWEN-250
// Larry Kiser December 10, 2024


#define BOGUS_POINTER (char *)1
#define BAD_PARAMETERS (-999999)

// structs
struct grade_stats 
{
	int a_grades ;			// number of A grades
	int b_grades ;			// number of B grades
	int c_grades ;			// number of C grades
	int d_grades ;			// number of D grades
	int f_grades ;			// number of F grades
} ;


// cfinal functions
char *make_string_of_letters( char start_letter, int number_of_letters ) ;
int count_grades( int *p_grades, int grade_count, struct grade_stats *p_stats ) ;
int extract_number( char *input, int *number_found ) ;
int fix_bad_code( char *pstring ) ;

