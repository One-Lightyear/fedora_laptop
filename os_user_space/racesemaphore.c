#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>


#define KEY1 1119


struct share
{
	int operand;
}*sh_mem;

union semun
{
	int value;
	int *array;
};


int main()
{
   int ret,status,id,semid,ret1;
 
   int i=0,j=0;
 
   struct sembuf sb;
 
   union semun u1;
   u1.value=1;
 
   id =  shmget(KEY1,getpagesize(),IPC_CREAT|0600);
   if(id<0)
   {
	   printf("Error creating shared memory\n");
	   exit(1);
   }

   semid = semget(KEY1,1,IPC_CREAT|0666);
   if(semid<0)
   {
	   printf("Error creating semaphore object\n");
	   exit(2);
   }

   sh_mem = shmat(id,0,0); 
   ret1 = semctl(semid,0,SETVAL,u1);
   if (ret1<0)
   {
	   perror("Error in semaphore setting");
	   exit(3);
   }


  while(i++<2)
  {
	ret = fork();
        sh_mem->operand=100;
	if(ret<0)
	{
           perror("error in fork"); 
           exit(1); 
	}

	if(ret>0&&i==1)
	{ 
           printf("in parent : ppid is %d and pid is %d\n",getppid(),getpid());	   
           continue;
   	}

	if(ret==0) 
  	{ 
           printf("in child_%d : ppid is %d and pid is %d\n",i,getppid(),getpid());	   
		if(i==1)
		{
          	while(++j<6) 
	   	{
			sb.sem_num = 0;  //semaphore instance no.
        		sb.sem_op = -1;  //decrement operation
        		sb.sem_flg = 0;  //not using flags
        		semop(semid,&sb,1);

			printf("1\n");
			sh_mem->operand++;

			sb.sem_num = 0;  //semaphore instance no.
        		sb.sem_op = +1;  //decrement operation
        		sb.sem_flg = 0;  //not using flags
        		semop(semid,&sb,1);
	   	}
	   	exit(0);
		}


	       	if(i==2);
		{
           	while(++j<6)
	   	{
			sb.sem_num = 0;  //semaphore instance no.
        		sb.sem_op = -1;  //decrement operation
        		sb.sem_flg = 0;  //not using flags
        		semop(semid,&sb,1);

			printf("2\n");
			sh_mem->operand--;

			sb.sem_num = 0;  //semaphore instance no.
        		sb.sem_op = +1;  //decrement operation
        		sb.sem_flg = 0;  //not using flags
        		semop(semid,&sb,1);
	   	}
           	exit(0); 
		}
	}
 }


//Block to clear zombies and destroy shared memory
 if(ret>0)
 {
   while(1)
   {
    ret = waitpid(-1,&status,0);
    if(ret>0)
    {
    printf("The terminated childs' pid is %d\n",ret);	    
    if(WIFEXITED(status))
    {
       if(WEXITSTATUS(status) == 0)
       { 
	       printf("normal and successfull\n");
       }
       else
       {
	       printf("normal, but not successfull\n");
       }
    }
    else
    { 
	printf("abnormal (did not succeed)\n");
    }
   }
    if(ret<0) 
    { 
	printf("counter value is : %d\n",sh_mem->operand); 
        shmctl(id,IPC_RMID,0);//destroy the shared memory
        exit(0); 

    }
   }
  }

return 0;
}
