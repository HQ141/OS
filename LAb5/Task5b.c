#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    int a=fork();
    if(a){
        wait(NULL);
        printf("I am Process 6 my PID is %d\n",getpid());
        exit(0);
    }
    else{
        printf("I am Process 9 my PID is %d\n",getpid());
        exit(0);
    }
}