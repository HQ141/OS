#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    int a=fork();
    if(a){
        wait(NULL);
        printf("I am Process 8 my PID is %d\n",getpid());
        exit(0);
    }
    else{
        pid_t arr[2];
        int i;
        for(i=0;i<2;i++){
        arr[i]=fork();
        if(!arr[i])
        break;
        }
        if(i==0){
            printf("I am Process 7 my PID is %d\n",getpid());
            exit(0);
        }
        if(i==1){
            printf("I am Process 2 my PID is %d\n",getpid());
            exit(0);
        }
        while((wait(NULL)>0))
        i=i;
        printf("I am Process 0 my PID is %d\n",getpid());
        exit(0);
    }
}