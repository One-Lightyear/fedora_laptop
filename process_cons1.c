#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<errno.h>

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
	struct sembuf semp[3];
	unsigned short arr[3];
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
	u1.arr=arr;
	ret1=semctl(sem_id,0,GETALL,u1);
        if(ret1<0)
	{
               perror("Error in getting semaphore");
	       exit(1);
	}
	//printf("Values=%d %d %d",arr[0],arr[1],arr[2]);
        while(1)
	{
	//if(shma->read==50)
	//{
	//	sleep(120);
//	}
	      semp[0].sem_num=2;
	      semp[0].sem_op=-1;
	      semp[0].sem_flg=0;
	      semp[1].sem_num=1;
              semp[1].sem_op=-1;
	      semp[1].sem_flg=0;
	      ret1=semop(sem_id,semp,2);
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
	//printf("\nValues after dec binary semaphore=%d %d %d",arr[0],arr[1],arr[2]);
        if((shma->userCount)!=0)
	      {
		      value1=shma->buf[shma->read];
		      printf("\nValue read at %d is %d \n",shma->read,value1);
		      shma->read=((shma->read+1)%MaxCount);
		      shma->userCount--;
	      }
              semp[0].sem_num=0;
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
	//printf("\nValues after incrementing binary semaphore=%d %d %d",arr[0],arr[1],arr[2]);
	}
	exit(0);
}

