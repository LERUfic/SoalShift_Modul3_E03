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
char *buffer;
void* cek_nama(void *arg){
    char dicari[256];
    int count=0;
    strcpy(dicari,arg);
    printf("dicari %s\n",dicari);
    while(stack!=-1){
        if(strstr(buffer,dicari)!=NULL){
            count++;
            stack--;
        }
        while(stack);
    }
    return NULL;
}


int main(int argc,char *argv[]){

if( argc != 3 ) {
    printf("input invalid , masukkan 2 string\n");
    return 0;
}
printf("benar\n");
    fail =fopen("Novel.txt","r");
    pthread_create(&(tid1), NULL, &cek_nama,(void *)argv[1]);
    pthread_create(&(tid2), NULL, &cek_nama,(void *)argv[2]);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    size_t in=0;

    while(getline(&buffer,&in,fail)!=-1){
        stack=2;
        while(stack=!0);
    }
    stack = -1;
    fclose(fail);

    return 0;
}
