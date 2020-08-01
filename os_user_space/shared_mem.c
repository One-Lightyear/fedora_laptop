#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>         //declares and comprises POSIX API
#include <sys/types.h>      //_t definitions
#include <sys/wait.h>       //Waitpid library
#include <sys/ipc.h>        //ipc library
#include <sys/shm.h>        //shared memory libraries
#include <sys/sem.h>        //semaphore library

#define KEY1 9087
#define KEY2 1234


union senum
{
      int val;
      struct semid_ds *buf;
      unsigned short *array;
      struct seminfo *__buf;
}u1;


struct shmarea{
	long count;
}*shma;

int main()
{
	int id_shmem,id_semaphore,ret,i=0,status=0,ret1;
	
	struct sembuf sboa;

	id_shmem = shmget(KEY1,sizeof(struct shmarea),IPC_CREAT|0777);				// Create a shared memory identifier
        if(id_shmem==-1)
	{
		perror("Error in share memory creation\n");
		printf("Error No:%d->%s",errno,strerror(errno));
		exit(1);
	}
	
	shma=shmat(id_shmem,0,0);								// Attatch the shared memory
	if(shma<0)
	{
		perror("Error in share memory attachment!\n");
		printf("Error No:%d",errno);
		exit(1);
	}


	id_semaphore=semget(KEY2,1,IPC_CREAT|0777);
	if(id_semaphore<0)
	{
               perror("Error in semaphore creation!");
	       printf("Error no: %d",errno);
	       exit(1);

	}

	u1.val=1;
	ret1=semctl(id_semaphore,0,SETVAL,u1);
	if(ret1<0)
	{
               perror("Error in semaphore creation!");
	       printf("Error no: %d",errno);
	       exit(1);
	}
	
       
	while(i++<=2)
	{ ret=fork();

                if(ret==-1)
                {
                        perror("fork status");
                        exit(EXIT_FAILURE);
                }

                if(ret>0 && i==1)
                {
                        printf("pid of parent (i.e. ppid of the child processes) = %d.\n",getpid());

                }

                if(ret==0)
                {
                        if(i==1)
                        {
                                printf("Child process no. %d created with pid = %d.\n",i,getpid());
                                for(int j=1;j<=10;j++)
				{
                                        sboa.sem_num=0;
                                        sboa.sem_op=-1;
                                        sboa.sem_flg=0;
                                        ret1=semop(id_semaphore,&sboa,1);
					
					shma->count++;
                               		printf("child no. %d count=%ld\n",i,shma->count);
                                        
					sboa.sem_num=0;
                                        sboa.sem_op=+1;
                                        sboa.sem_flg=0;
                                        ret1=semop(id_semaphore,&sboa,1);
				}
                                exit(EXIT_SUCCESS);
                        }

                        if(i==2)
                        {
                                printf("Child process no. %d created with pid = %d.\n",i,getpid());
                                for(int j=1;j<=5;j++)
				{
                                        sboa.sem_num=0;
                                        sboa.sem_op=-1;
                                        sboa.sem_flg=0;
                                        ret1=semop(id_semaphore,&sboa,1);
					
					shma->count--;
					printf("child no. %d count=%ld\n",i,shma->count);
                        
					sboa.sem_num=0;
                                        sboa.sem_op=+1;
                                        sboa.sem_flg=0;
                                        ret1=semop(id_semaphore,&sboa,1);
				}

                                exit(EXIT_FAILURE);
                        }

		}
	}

	if(ret>0)
        {
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
				printf("%d\n",shma->count);
                                printf("All the child processes are terminated.\n");
				shmctl(id_shmem,IPC_RMID,0);
				semctl(id_semaphore,0,IPC_RMID);
				shmdt(shma);
				printf("Parent terminating!\n");
                                exit(EXIT_SUCCESS);
                        }
                }
        }
}

