#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int sum[2];
int *arr= {1,2,3,4,5,6,7,8,9,10};

void *Sum (void* x){	
	int j = (int) x;
    sum[j]=0;
    if(j)
	for (int i =0 ; i < 5 ; i++ )
		sum[j] += arr[i];
    else
    for(int i=5;i<10;i++)
        sum[j]+=arr[i];
	
}
int main(){
	pthread_t thread[2];
	for (int i = 0 ; i < 2 ; i++)
	pthread_create(&thread[i], NULL , Sum , (void*)i);
	for (int i = 0 ; i < 2 ; i++)
	pthread_join(thread[i], NULL);	
	int total = 0;
	for (int i = 0 ; i < 2 ; i++){
		printf("The sum of this thread is : %d\n" , sum[i]);
		total +=sum[i];
	}	
	printf("The collective sum is : %d\n " , total);
	return 0;
}