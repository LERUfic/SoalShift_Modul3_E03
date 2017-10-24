#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int now, hasil=1, bil, status=1;

void* faktorial(void *arg){
    for(int i=1;i<= bil;i++){
        hasil=i*hasil;
    }
    status++;
    printf("%d!= %d\n",bil,hasil);
}

int main(int argc, int *argv[])
{
    pthread_t tid[argc];

    for(int i=1;i<=argc;i++){
        now = i;
        printf("------->%c\n", (int)*argv[i]);
        bil = (int)*argv[i]-(int)'0';
        pthread_create(&(tid[i]),NULL,&faktorial,NULL);
        while(status-1!=i){}
    }

    return 0;
}
