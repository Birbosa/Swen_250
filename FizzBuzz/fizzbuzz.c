#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
int main ( )
{
	int count = 1;
	while (count <= 100){
		if( count % 5 == 0 && count % 7 == 0){
			printf("FizzBuzz\n");
		}
		else if (count % 5 == 0){
			printf("Fizz\n");
		}
		else if ( count % 7 == 0){
			printf("Buzz\n");
		}
		else{
			printf("%d",count);
		}
		count += 1;
		}
	return 0;
}
