#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void * func(void* a){
    printf("thread %ld\n",a);
    return 0;
}
int main(){
    pthread_t thread[3];
    for(long i=0;i<3;i++)
    if(pthread_create(&thread[i],NULL,func,(void*)i)!=0){
        printf("Error");
        exit(1);
    }
    void * a;
    for(int i=0;i<3;i++){
        pthread_join(thread[i],&a);
        printf("thread %d returned %ld\n",i,(long*)a);
    }
}