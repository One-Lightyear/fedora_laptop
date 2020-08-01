#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/sem.h>

#define Key1 1234
#define Key2 7654
#define MaxCount 50

struct shmarea{
	unsigned int read;
	unsigned int write;
	unsigned int userCount;
	int buf[50];
};

union semun{
	int val;
	struct semid *_buf;
	struct seminfo *buf;
	unsigned short *arr;
}u1;

int main()
{
	struct sembuf semp[3],sb1,sb2,sb3;
	unsigned short arr1[3]={50,1,0},arr[3];
	int shm_id,sem_id,ret,ret1,ret2,ret3;
	int value1;
        struct shmarea *shma;
        shm_id=shmget(Key1,3*4096,IPC_CREAT|0666);
	if(shm_id<0)
	{
           perror("Error in share memory creation");
	   exit(1);
	}
	shma=shmat(shm_id,0,0);
        if(shma<0)
	{
		perror("Error in attaching memory");
		exit(1);
	}
	sem_id=semget(Key2,3,IPC_CREAT|0600);
	if(sem_id<0)
	{
		perror("Error in semaphore creation");
		exit(1);
	}
	shma->read=0;
	shma->write=0;
	shma->userCount=0;
        u1.arr=arr;
	ret1=semctl(sem_id,0,GETALL,u1);
        if(ret1<0)
	{
               perror("Error in getting semaphore");
	       exit(1);
	}
	//printf("Values=%d %d %d",arr[0],arr[1],arr[2]);
        u1.arr=arr1;

	ret=semctl(sem_id,0,SETALL,u1);
        if(ret<0)
	{
               perror("Error in setting semaphore");
	       exit(1);
	}

        u1.arr=arr;
	ret1=semctl(sem_id,0,GETALL,u1);
        if(ret1<0)
	{
               perror("Error in getting semaphore");
	       exit(1);
	}
	//printf("Values=%d %d %d",arr[0],arr[1],arr[2]);
	//printf("ID=%d value =%d",semctl(sem_id,0,Getid,u1.val),semctl(sem_id,0,Getval,u1.val));
        while(1)
	{
        u1.arr=arr;
	ret1=semctl(sem_id,0,GETALL,u1);
        if(ret1<0)
	{
               perror("Error in getting semaphore");
	       exit(1);
	}
	//printf("Values=%d %d %d",arr[0],arr[1],arr[2]);
              printf("\nEnter the value to be added:\n ");
	      //ret2=read(STDIN_FILENO,&value,1);
	      scanf("%d",&value1);
	      //__fpurge(stdin);
	  //    printf("\nEntered value is:%d",value1);
	    //  fflush(stdout);

        u1.arr=arr;
	ret1=semctl(sem_id,0,GETALL,u1);
        if(ret1<0)
	{
               perror("Error in getting semaphore");
	       exit(1);
	}
	if(shma->write==50)
	{
		shma->write=0;
		//sleep(120);
	}
	//printf("\nValues=%d %d %d",arr[0],arr[1],arr[2]);
	      semp[0].sem_num=0;
	      semp[0].sem_op=-1;
	      semp[0].sem_flg=0;
	      //ret1=semop(sem_id,&sb1,1);
	      semp[1].sem_num=1;
              semp[1].sem_op=-1;
	      semp[1].sem_flg=0;
	      ret1=semop(sem_id,semp,2);
	      //printf("\nsemop ret=%d",ret1);
	      if(ret1<0)
	      {
		      perror("Semop error");
	      }
        u1.arr=arr;
	ret1=semctl(sem_id,0,GETALL,u1);
        if(ret1<0)
	{
               perror("Error in getting semaphore");
	       exit(1);
	}
	//printf("\nValues after dec binary semaphore=%d %d %d\n",arr[0],arr[1],arr[2]);
		//printf("\nusercount=%d write=%d",shma->userCount,shma->write);
              if((shma->userCount)<MaxCount)
	      {
		      shma->buf[shma->write]=value1;
		     // if(shma->write==49)
		//	      shma->write=0;
		  //    else
			      shma->write++;//=((shma->write+1)%MaxCount);
		      shma->userCount++;
		      printf("\n Value entered in buffer at %d is %d\n",(shma->write-1),shma->buf[(shma->write)-1]);
	      }
	      
	      semp[0].sem_num=2;
	      semp[0].sem_op=+1;
	      semp[0].sem_flg=0;
	      //semop(sem_id,&sb3,1);
	      semp[1].sem_num=1;
              semp[1].sem_op=+1;
	      semp[1].sem_flg=0;
	      semop(sem_id,semp,2);
        u1.arr=arr;
	ret1=semctl(sem_id,0,GETALL,u1);
        if(ret1<0)
	{
               perror("Error in getting semaphore");
	       exit(1);
	}
	//printf("\nValues after incrementing binary semaphore=%d %d %d\n",arr[0],arr[1],arr[2]);
	}
	exit(0);
}

