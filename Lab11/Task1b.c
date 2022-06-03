#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int icecreamremaining;
sem_t mutex;
void* eat(void * i){
    long n=(long)i;
    while (1){
        sem_wait(&mutex);
        if(!icecreamremaining){
            sem_post(&mutex);
            exit(0);
        }
        sleep(2);
        icecreamremaining--;
        printf("%d has decremented ice cream.%d remaining\n",n,icecreamremaining);
        sem_post(&mutex);
        //sleep(0.00005);
    }
    
}
int main(){
    //printf("Enter total icecream\n");
    //scanf("%d",&icecreamremaining);
    icecreamremaining=10;
    pthread_t contest[3];
    sem_init(&mutex,0,1);
    long i=0;
    for(i=0;i<3;i++){
    pthread_create(&contest[i],NULL,eat,(void *)i);
    }
    //pthread_exit(NULL);
    for(i=0;i<3;i++){
    pthread_join(contest[i],NULL);
    }
    printf("exiting\n");
}

