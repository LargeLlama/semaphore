#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>

// NOT TESTED YET PLS TEST LMK IN THEORY IT WORKS

int main(){
	int semkey = 1000;
	int sem_id = semget(semkey, 1, 0); //Get semaphore's id
	if (sem_id < 0){
		printf("ERROR\n");
	}
	else{
		if(semctl(sem_id, 0, GETVAL, 0)){ //If the value in the semaphore is not 0...
			sembut operation;
			operation.sem_num = 0;
			operation.sem_op = -1;
			operation.sem_flg = SEM_UNDO;
			semop(sem_id, operation, 1); //Decrease the semaphore by 1

			int shmkey = 1000;
			char * data;
			shm_id = shmget(key, 100, 0666 | IPC_CREAT);
			data = shmat(shmid, (void *)0, 0); //Put the shared data into char * data

			if(!data[0]){
		    printf("Segment was just created\n");
		  }
		  else{
		    printf("last line: %s\n", data);
		  }

			printf("Next line?\n");
    	fgets(data,200,stdin); // Replace the shared data with the new data
    	data[strlen(data)-1] = 0;

			file_desc = fopen("file", O_WRONLY | O_APPEND);
			write(file_desc, data, strlen(data)); // Append the data into the file

			if(!semctl(sem_id, 0, GETVAL, 0)){ //Check if the semaphore is at 0
				operation.sem_op = 1;
				semop(sem_id, operation, 1); //Increase the semaphore back to 1
			}
		}
	}
	printf("WIP!\n");
	return 0;
}
