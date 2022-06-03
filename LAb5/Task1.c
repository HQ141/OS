#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    int a=fork();
    if(a<0){
        printf("UnSuccessful Child Creation\n");
        exit(0);
    }
    if(a==0){
    printf("Parent id=%d",getppid());
    int i;
    for(int i=0;i<10;i++)
    printf("%d\n",i);
    printf("Child Ends\n");
    }
    if(a>0){
    wait(NULL);
    for(int i=0;i<10;i++)
    printf("%d\n",i);
    printf("Parent Ends\n");
    }
}