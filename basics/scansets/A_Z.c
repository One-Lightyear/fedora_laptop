/* The data range inside the [] indicates what range of chars will be taken as input  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[128];
    	printf("Enter a string: ");
    	scanf("%[A-Z]s", str);

    	printf("You entered: %s\n", str);

    	return 0;
}
