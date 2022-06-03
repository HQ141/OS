#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
sem_t weight;
sem_t security;
sem_t boarding;
void* Boarding(void *i){
    int num=(long) i;
    printf("passenger %d arrived\n",num);
    sem_wait(&weight);
    printf("passenger %d weighing luggage\n",num);
    sleep(4);
    printf("passenger %d completed weighting luggage\n",num);
    sem_post(&weight);
    sem_wait(&security);
    printf("passenger %d in security check\n",num);
    sleep(7);
    printf("passenger %d completed security check\n",num);
    sem_post(&security);
    sem_wait(&boarding);
    printf("passenger %d getting boarding pass\n",num);
    sleep(3);
    printf("passenger %d completed boarding\n",num);
    sem_post(&boarding);
}
int main(){
    pthread_t passenger[10];
    long i;
    sem_init(&boarding,0,1);
    sem_init(&security,0,1);
    sem_init(&weight,0,1);
    for(i=0;i<10;i++)
    pthread_create(&passenger[i],NULL,Boarding,(void *)i);
    for(i=0;i<10;i++)
    pthread_join(passenger[i],NULL);
    
}