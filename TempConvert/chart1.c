#include <stdlib.h>
#include <stdio.h>
int main( )
{
	int fahr = 0 ;
	int cel = 0 ;

	printf("%3s%10s\n", "Fahrenheit","Celsius");
	while (fahr <= 300){
		cel = ((fahr-32)*5/9);
		printf("%3d%10d\n", fahr, cel) ;
		fahr += 20;
	}
}
