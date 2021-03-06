#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <semaphore.h>

int main(int argc, char **argv)
{
	key_t key = 1000;
	int sem_key = 1000;

	int sem_id;
	int shm_id;
	char contents[100];
	int file_desc;

	if (argc > 1)
	{
		if (!strcmp(argv[1], "-c"))
		{
			shm_id = shmget(key, 100, 0666 | IPC_CREAT);
			file_desc = open("file", O_CREAT | O_TRUNC);
			printf("Able to make the shared memory and open the file\n");
			sem_id = semget(sem_key, 1, 0);

		}
	}
	else
	{
		printf("Invalid arguments provided! Exiting!\n");
		return 1;
	}
	return 0;
}
