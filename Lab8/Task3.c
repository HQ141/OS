#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void * func(void* a){
    printf("Hello from thread %d\n",(int *)a);
}
int main(int argc,char *argv[]){
    int a=atoi(argv[1]);
    pthread_t threads[100];
    for(long i=0;i<a;i++){
        if(i%4==0)
        sleep(1);
        printf("Creation of thread %ld\n",i);
        pthread_create(&threads[i],NULL,func,(void* )i);
    }
    pthread_exit(NULL);
}