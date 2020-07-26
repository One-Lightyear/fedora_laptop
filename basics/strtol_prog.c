#ifdef __GNUC__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int main(int argc, char **argv, char **envp)
{
	long int val=0;

	char *data,*endptr;
	printf("Enter the data to convert :");
	data=(char*)malloc(100*sizeof(char));

	gets(data);

        val = strtol(data, &endptr, 0);

        /* Check for various possible errors */

        if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
                || (errno != 0 && val == 0)) {
            perror("strtol");
            exit(EXIT_FAILURE);
        }

       if (endptr == data) {
            fprintf(stderr, "No digits were found\n");
            exit(EXIT_FAILURE);
        }

        printf("strtol() returned %ld\n", val);

        if (*endptr != '\0') printf("Further characters after number: %s\n", endptr);

        exit(EXIT_SUCCESS);

}

#endif
