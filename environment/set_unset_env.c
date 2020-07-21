/* 
 *
 * -- Intension is to use the setenv, putenv, getenv, unsetenv & clearenv functions in "<stdlib.h>".
 * 
 * -- setenv, putenv & unset, returns 0 upon success.
 * -- Upon failure, returns -1 & errno is set.
 * -- Also error -> ENOMEM, if insufficient space to allocate new env.
 * --or EINVAL -> if invalid arguement
 * 
 * -- Unsetenv completely removes the env variable.
 *  --clearenv(void), completely deletes all the env values.
 * 
 * -- setenv -> Trying to create an env variable already existing with the same name=value pair
 *    doesn't override, but returns "success".
 * -- putenv -> Anyway replaces the whole key=value if exist, & if not exist, create new.   
 * -- unsetenv -> Trying to unset an env var. that doesnt exists, returns "success" too.
 * 
 * -- Env value is updated only if overwrite is "non-zero".
 * -- If overwrite is "0", value not changed, but returns success.
 *
 * -- Syntaxes:
 * 	-- int setenv(const char *name, const char *value, int overwrite);
 *	-- int putenv("name=value");
 * 	-- int unsetenv(const char *name);
 * 	-- void clearenv(void);
 *
 * -- Getenv:
 * -- The getenv() function searches the environment list  to  find the  environment  variable name,
 *    and returns a pointer to the corresponding value string.
 * -- Returns NULL if no value found for the name.
 * -- char *getenv(const char *name);
   
 *
 *
 */

#ifdef __GNUC__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void printerr()
{
	fprintf(stderr,"err no. -> %d, err statement -> %s "\
			,errno, strerror(errno));
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **envp)
{
/*	if(setenv("KPATH","/usr/src/",0)!=0)	// New var no overlapping
	{
		printerr();
	}
*/
	printf("%d",getpid());
	putenv("HOME=/use/path");
	puts(getenv("HOME"));
	return 0;
}


#endif
