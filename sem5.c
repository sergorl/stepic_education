#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
           int              val;    /* Value for SETVAL */
           struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
           unsigned short  *array;  /* Array for GETALL, SETALL */
           struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                       (Linux specific) */
};

int main()
{
    key_t key = ftok("/tmp/sem.temp", 1);
    int sem = semget(key, 16, 0777 | IPC_PRIVATE);
    
    for(size_t i = 0; i<16; ++i) {
    	union semun arg;
    	arg.val = i ;
    	semctl(sem, i, SETVAL, arg);
    }
    
    printf("ok.\n");

    return 0;
}
