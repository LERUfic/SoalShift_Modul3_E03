#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>


void* faktorial(void *arg){
    int bil = (int*)arg;
    int hasil=1;
    for(int i=2;i<= bil;i++){
        hasil=i*hasil;
    }
    printf("%d!= %d\n",bil,hasil);
}


int main(int argc,char *argv[]){

    pthread_t tid[argc];
    int bil;
    for(int i=1;i<argc;i++){

        int j=0;
        bil=atoi(argv[i]);

        pthread_create(&(tid[i]),NULL,&faktorial,(void*)bil);
        pthread_join(tid[i],NULL);
    }

    return 0;
}

