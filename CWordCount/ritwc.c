#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

static int state = 0 ; // protected state value

// when called the first time returns a 0
// next call returns 1
// 3rd call return 0 and continues to return 0, 1, 0, 1 etc.
int state_toggle( void )
{

	if ( state > 1 )
		state = 0 ;

	return state++ ;
}

int main() {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */

	/* REPLACE WITH ADDITIONAL VARIABLE DECLARATIONS YOU NEED */
	int next_char = '\0' ;
        int space = 0;	
	/* REPLACE WITH THE CODE FOR WORD COUNT */
	next_char = getchar() ;

	while (next_char != EOF){
	
		if (iscntrl(next_char)){
			tot_lines ++;
		}
		if (isspace(next_char) && space == 0){
			tot_words ++ ;
			space ++;
		}
		else if (!isspace(next_char)){
			space = 0;
		}

			tot_chars ++ ; 
		
		next_char = getchar();


	}
	printf(" %d  %d %d\n", tot_lines, tot_words, tot_chars);

	return 0 ;
}
