#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;

/*
status 0 pemain1 input trap
status 1 pemain2 tebak trap
status 2 pemain2 input trap
status 3 pemain1 tebak trap

*/
int status;
int nomor,jumlah;
int skor1=0,skor2=0;
char ladang1[17];
char ladang2[17];

void* pemain1(void *arg){

    while(1){
        status%=3;
        printf("pemain 1, [jumlah trap] [nomor ladang sebanyak jumlah trap dipisahkan spasi]\n> ");
        scanf("%d",&jumlah);
        while(jumlah--){
            scanf("%d",&nomor);
            ladang1[nomor]='x';
        }
        status=1;
        while(status==1);

    }
    return NULL;
}


void* pemain2(void *arg)
{
    while(1){
        status%=3;
        while(status==0);
        scanf("%d",&nomor);

    }


    return NULL;

}

int main(void){

    for(int i=1;i<=16;++i){
        ladang1[i]='o';
        ladang2[i]='o';
    }
    pthread_create(&(tid1), NULL, &pemain1, NULL);
    pthread_create(&(tid2), NULL, &pemain2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
