#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;

/*
status 0 pemain1 input trap
status 1 pemain2 tebak trap lalu pemain2 input trap
status 2 pemain1 tebak trap
status 3 game over

*/
int status;
int nomor,jumlah;
int skor1=0,skor2=0,stok1=16,stok2=16;
char ladang1[17];
char ladang2[17];

void* pemain1(void *arg){

    while(1){
        printf("skor pemain1 : %d\nskor pemain2 : %d\n",skor1,skor2);
        status=0;
        printf("pemain 1, [jumlah trap] [nomor ladang sebanyak jumlah trap dipisahkan spasi]\n> ");

        scanf("%d",&jumlah);

        while(jumlah--){
            scanf("%d",&nomor);
            //asumsi field yang sudah terisi,bisa di isi lagi,sehingga tidak berpengaruh
            if(ladang1[nomor]=='o')stok1--;
            ladang1[nomor]='x';
        }
        status=1;
        while(status==1||status==3){
            if(status==3)return NULL;
        }
        printf("pemain 1, [nomor ladang tebak]\n> ");

        scanf("%d",&nomor);
        if(ladang2[nomor]=='o'){
            printf("tebakan pemain1 benar!, poin pemain1 ditambah 1\n");
            ++skor1;
        }
        else{
            printf("tebakan pemain1 salah!, poin pemain2 ditambah 1\n");
            ++skor2;
        }
        if(skor1==10 || skor2 == 10 || stok1==0 || stok2==0){status=3;return NULL;}
    }
    return NULL;
}


void* pemain2(void *arg){
    while(1){
        status=0;
        while(status==0||status==3){
            if(status==3)return NULL;
        }
        printf("pemain 2, [nomor ladang tebak]\n> ");
        scanf("%d",&nomor);
        if(ladang1[nomor]=='o'){
            printf("tebakan pemain2 benar!, poin pemain2 ditambah 1\n");
            ++skor2;
        }
        else{
            printf("tebakan pemain2 salah!, poin pemain1 ditambah 1\n");
            ++skor1;
        }
        if(skor1==10 || skor2 == 10 || stok1==0 || stok2==0){status=3;return NULL;}

        printf("skor pemain1 : %d\nskor pemain2 : %d\n",skor1,skor2);
        printf("pemain 2, [jumlah trap] [nomor ladang sebanyak jumlah trap dipisahkan spasi]\n> ");
        scanf("%d",&jumlah);
        while(jumlah--){
            scanf("%d",&nomor);
            if(ladang2[nomor]=='o')stok2--;
            ladang2[nomor]='x';
        }
        status=2;
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
