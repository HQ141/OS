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
    if(i==2){
            while(wait(NULL)>0)
            i=i;
            printf("I am Process A my PID is %d\n",getpid());
            exit(0);
        }
    if(i==1){
            for(i=0;i<2;i++){
            a[i]=fork();
            if(!a[i])
            break;
        }
        if(i==2){
            while(wait(NULL)>0)
            i=i;
            printf("I am Process C my PID is %d\n",getpid());
            exit(0);
        }
        printf("I am Process %c my PID is %d\n",(i==1)?'F':'E',getpid());
        exit(0);
    }
    if(i==0){
        a[i]=fork();
        if(!a[i]){
            while(wait(NULL)>0)
            i=i;
            printf("I am Process B my PID is %d\n",getpid());
            exit(0);
        }
        printf("I am Process D my PID is %d\n",getpid());
        exit(0);
    }
}