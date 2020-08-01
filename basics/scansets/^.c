/* The characters until the char followed by ^ will be entered */


#include <stdio.h>
#include <stdlib.h>

int main()
{

	char str[128];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    printf("You entered: %s\n", str);

    return 0;
}
