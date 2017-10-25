#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t tid1;
pthread_t tid2;
FILE* fail;
/*
stack [1,2] = masih ada yang lagi compare string
stack -1 : terminate
*/
int stack=2;
void* cek_nama(void *arg){
    FILE *fail;
    fail =fopen("Novel.txt","r");
    char dicari[256];
    int count=0;
    char buffer[256];
    strcpy(dicari,arg);
    while(fscanf(fail,"%s",buffer)!=EOF){
        if(strstr(buffer,dicari)!=NULL){
            count++;
        }
    }
    fclose(fail);
    printf("%s : %d\n",dicari,count);
    return NULL;
}


int main(int argc,char *argv[]){

pthread_t tid[argc];

for(int i=1;i<argc;++i){
    pthread_create(&(tid[i]), NULL, &cek_nama,(void *)argv[i]);
}
for(int i=1;i<argc;++i){
    pthread_join(tid[i], NULL);
}

    return 0;
}
