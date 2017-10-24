#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int hewan[2];

void* krglohan(void *arg){
    while(1){
        sleep(10);
        hewan[0]=hewan[0]-15;
        if(hewan[0]<=0 || hewan[1]<=0 || hewan[0]>100 || hewan[1]>100){
            exit(EXIT_FAILURE);
        }
        else{
            printf("\nKondisi Lohan %d\n", hewan[0]);
            printf("Kondisi Kepiting %d\n", hewan[1]);
        }
    }
}

void* krgkepiting(void *arg){
    while(1){
        sleep(20);
        hewan[1]=hewan[1]-10;
        if(hewan[0]<=0 || hewan[1]<=0 || hewan[0]>100 || hewan[1]>100){
            exit(EXIT_FAILURE);
        }
        else{
            printf("\nKondisi Lohan %d\n", hewan[0]);
            printf("Kondisi Kepiting %d\n", hewan[1]);
        }
    }
}

int main(void)
{
    hewan[0]=100; //lohan
    hewan[1]=100; //kepiting

    pthread_t tid[2];

    pthread_create(&(tid[0]),NULL,&krglohan,NULL);
    pthread_create(&(tid[1]),NULL,&krgkepiting,NULL);

    while(1){
        if(hewan[0]<=0 || hewan[1]<=0 || hewan[0]>100 || hewan[1]>100){
            printf("status lohan = %d\n", hewan[0]);
            printf("status kepiting = %d\n", hewan[1]);
            break;
        }
        else{

            int pilih;
            printf("Kasih Makan Hewan:\n");
            printf("1. Lohan 10\n");
            printf("2. Kepiting 10\n");
            printf("========\nUser Input: ");
            scanf("%d",&pilih);

            if(pilih==1){
                hewan[0] = hewan[0]+10;
                printf("\nKondisi Lohan %d\n", hewan[0]);
                printf("Kondisi Kepiting %d\n", hewan[1]);
            }
            else if(pilih==2){
                hewan[1] = hewan[1]+10;
                printf("\nKondisi Lohan %d\n", hewan[0]);
                printf("Kondisi Kepiting %d\n", hewan[1]);
            }
        }
    }

    return 0;
}
