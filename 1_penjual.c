#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
//   MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE
//idx  0       1      2      3         4      5
void main()
{
        key_t key = 1234;
        int *stok;


        int shmid = shmget(key, sizeof(int)*6, IPC_CREAT | 0666);
        stok = shmat(shmid, NULL, 0);
        for(int i=0;i<6;++i){
            stok[i]=0;
        }

        char seq[50];

        while(1){
            scanf("%s",&seq);



        }



        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}
