#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int now, hasil=1, bil, status=1;

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

        int j=strlen(argv[i])-1;
        bil=0;
        while(j>-1){
            bil*=10;
            bil+=(argv[i][j]-48);
            //printf("x: %d ",argv[i][j]-'0');
            --j;
        }
        pthread_create(&(tid[i]),NULL,&faktorial,(void*)bil);
        pthread_join(tid[i],NULL);
    }

    return 0;
}
