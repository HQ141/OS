#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    int i;
    pid_t a[3];
    pid_t st=getpid();
    for(i=0;i<3;i++){
        a[i]=fork();
        if(a[i]==0){
            sleep(3*(2-i));
            break;
        }
    }
    if(i==2){
        printf("Child Three Exiting\n");
        exit(0);
    }
    if(i==1){  
        printf("Child 2 Exiting\n");
        exit(0);
    }
    if(i==0){
        printf("Child 1 exiting\n");
        exit(0);
    }
    if(getpid()==st){
        sleep(3);
        for(i=2;i>=0;i--){
            waitpid(a[i],NULL,0);
        }
        printf("Parent ends\n");
        exit(0);
    }
}