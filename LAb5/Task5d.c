#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t a[2];
    int i;
    for(i=0;i<2;i++){
        a[i]=fork();
        if(!a[i])
        break;
    }
    if(i==0){
        for(i=0;i<2;i++){
            a[i]=fork();
            if(!a[i])
            break;
        }
        if(i==0){
            printf("I am Process leaf my PID is %d\n",getpid());
            exit(0);
        }
        if(i==1){
            printf("I am Process leaf my PID is %d\n",getpid());
            exit(0);
        }
        while(wait(NULL)>0)
        i=i;
        printf("I am Process Inner Node my PID is %d\n",getpid());
        exit(0);
    }
    if(i==1){
        printf("I am Process Leaf my PID is %d\n",getpid());
        exit(0);
    }
    if(i==2){
        while(wait(NULL)>0)
        i=i;
        printf("I am Process Root my PID is %d\n",getpid());
        exit(0);
    }


}




