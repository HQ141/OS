#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void * table(void * a){
    long mu=(long)a;
    for(int i=0;i<1000;i++)
    printf("%ldx%d=%d\n",mu,i,mu*i);
}
int main(){
    pthread_t thread[4];
    for(long i=4;i<9;i++)
    pthread_create(&thread[i],NULL,table,(void *)i);
    pthread_exit(NULL);
}