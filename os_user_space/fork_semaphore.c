#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char** argv)
{

	pid_t ret=0;
	uint8_t i=0;

	while(++i<=3)
	{
		ret=fork();

		if(ret==-1)
		{
			perror("fork status");
			exit(EXIT_FAILURE);
		}

		if(ret>0 && i==1)
		{	
			printf("pid of parent (i.e. ppid of the child processes) = %d.\n",getpid());
		//	printf("pid of child %d=> %d\n",i,ret);
		//	kill(getpid(),SIGKILL);

		}

		if(ret==0)
		{
			if(i==1)
			{
				printf("Child process no. %d created eith pid = %d.\n",i,getpid());
				exit(EXIT_SUCCESS);
			}
			
			if(i==2)
			{
				printf("Child process no. %d created eith pid = %d.\n",i,getpid());
				exit(EXIT_FAILURE);
			}
			if(i==3)
			{
				printf("Child process no. %d created eith pid = %d.\n",i,getpid());
			//	while(1);
				pause();
				exit(EXIT_SUCCESS);
			}
		}
	}

	if(ret>0)
	{
		int status=0;
		while(1)
		{
			ret=waitpid(-1,&status,0);
			
			if(ret>0)
			{
				if(WIFEXITED(status))
				{
					if(WEXITSTATUS(status)==EXIT_SUCCESS)
						printf("Child process of pid = %d exited normally & successfully with exit status %d.\n",ret,WEXITSTATUS(status));
					else
						printf("Child process of pid = %d exited normally but unsuccessfully with exit status %d.\n",ret,WEXITSTATUS(status));
				}
				else if(WIFSIGNALED(status))
				{
					printf("Child process of pid = %d exited abnormally & unsuccessfully, killed by signal no. = %d.\n",ret,WTERMSIG(status));
				}
				else
					printf("Child process of pid = %d exited abnormally & unsuccessfully.\n",ret);
			}

			if(ret==-1)
			{
				printf("All the child processes are terminated.\n");
				exit(EXIT_SUCCESS);
			}
		}
	}
}
