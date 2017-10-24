#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;

/*
status 1 pemain1 input trap
status 2 pemain2 tebak trap
status 3 pemain2 input trap
status 4 pemain1 tebak trap

*/
int status;

int nomor;

void* pemain1(void *arg){

    while(1){


    }
    return NULL;
}


void* pemain2(void *arg)
{
    while(1){

    }
    return NULL;

}

int main(void)
{

    pthread_create(&(tid1), NULL, &pemain1, NULL);
    pthread_create(&(tid2), NULL, &pemain2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
