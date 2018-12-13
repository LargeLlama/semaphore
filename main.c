#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>


// A main writing program
// Will attempt to access the resources using the semaphore
// Once in, it should display the last line added to the file (use shared memory to contain the size of the last line).
// Prompt the use for the next line.
// Once a new line is read, write that to the file, update the shared memory and then release the semaphore

int main(){
	int semkey = 1000;
	int sem_id = semget(semkey, 1, 0);
	if (sem_id < 0){
		printf("ERROR\n");
	}
	else{
		if(semctl(sem_id, 0, GETVAL, 0)){
			sembut operation;
			operation.sem_num = 0;
			operation.sem_op = -1;
			operation.sem_flg = SEM_UNDO;
			semop(sem_id, operation, 1);

			int shmkey = 1000;
			char * data;
			shm_id = shmget(key, 100, 0666 | IPC_CREAT);
			data = shmat(shmid, (void *)0, 0);

			if(!data[0]){
		    printf("Segment was just created\n");
		  }
		  else{
		    printf("last line: %s\n", data);
		  }

			printf("Next line?\n");
    	fgets(data,200,stdin);
    	data[strlen(data)-1] = 0;

			file_desc = fopen("file", O_WRONLY | O_APPEND);
			write(file_desc, data, strlen(data));

			if(!semctl(sem_id, 0, GETVAL, 0)){
				operation.sem_op = 1;
				semop(sem_id, operation, 1);
			}
		}
	}
	printf("WIP!\n");
	return 0;
}
