#include <stdlib.h>
#include <stdio.h>
int main( )
{
        int fahr = 0 ;
        float cel = 0.0 ;
	
        printf("%3s%10s\n", "Fahrenheit","Celsius");
        while (fahr <= 300){
                cel = (float) (fahr-32)*5/9;
                printf("%3d%10.1f\n", fahr, cel) ;
                fahr += 20;
        }
	return 0;
}
