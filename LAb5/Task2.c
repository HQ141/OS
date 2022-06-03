#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    int a,p;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        p=fork();
        if(p>0){
            wait(NULL);
        }
        if(p==0){
            printf("Child ID=%d\n",getpid());
            exit(0);
        }
    }
}