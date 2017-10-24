#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
//   MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE
//idx  0       1      2      3         4      5
void main()
{
        key_t key = 1234;
        int *stok;
        char senjata[6][10];
        strcpy(senjata[0],"MP4A1");
        strcpy(senjata[1],"PM2-V1");
        strcpy(senjata[3],"SS2-V5");
        strcpy(senjata[2],"SPR-3");
        strcpy(senjata[4],"SPG1-V3");
        strcpy(senjata[5],"MINE");

        int shmid = shmget(key, sizeof(int)*6, IPC_CREAT | 0666);
        stok = shmat(shmid, NULL, 0);

        char name[50];
        int menu,val;
        printf("menu :\n1 lihat stock senjata\n2 tambah stock senjata\n");
        while(1){
            printf("pilihan menu > ");
            scanf("%d",&menu);
            if(menu==1){
                for(int i=0;i<6;++i){
                    if(stok[i]>0){
                        printf("Jumlah %s di stock = %d barang\n",senjata[i],stok[i]);
                    }
                }
            }
            else if(menu==2){
                printf("[nama_barang] [jumlah_barang] > ");
                scanf("%s %d",name,&val);
                for(int i=0;i<6;++i){
                    if(!strcmp(senjata[i],name)){
                        stok[i]+=val;
                        break;
                    }
                }

            }
        }



        shmdt(stok);
        shmctl(shmid, IPC_RMID, NULL);
}
