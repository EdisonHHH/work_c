#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <sys/shm.h>  
#include "shmdata.h" 
int main()
{
	void *shm=NULL;
	struct shared_type *shared=NULL;
	int shmid;
	shmid=shmget((key_t)1234,sizeof(struct shared_type),0666|IPC_CREAT);
	shm=shmat(shmid,(void*)0,0);
	shared=(struct shared_type*)shm;
	while(1){
		while(shared->flag){
			printf("waiting...\n");
			sleep(1);
		}
		printf("please enter some text:");
		fgets(shared->data,BUFSIZ,stdin);
		shared->flag=1;
		if(strncmp(shared->data, "end", 3) == 0){
				break;
		}
	}
	shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);
	return 0;
}

