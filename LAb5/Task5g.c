#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t a[3];
    int i;
    for(i=0;i<3;i++){
        a[i]=fork();
        if(!a[i])
        break;
    }
    if(i==3){
        while(wait(NULL)>0)
        i=i;
        printf("I am Process A my PID is %d\n",getpid());
        exit(0);
    }
    int aa;
    for(aa=0;aa<i;aa++){
        a[aa]=fork();
        if(!a[aa])
        break;
    }
    if(aa==i){
        while(wait(NULL)>0)
        i=i;
        if(i==0)
        printf("I am Process D my PID is %d\n",getpid());
        else if(i==1)
        printf("I am Process B my PID is %d\n",getpid());
        else if(i==2)
        printf("I am Process C my PID is %d\n",getpid());
        exit(0);
    }
    if(i==1){
    printf("I am Process E my PID is %d\n",getpid());
    exit(0);}
    if(aa=0){
    printf("I am Process F my PID is %d\n",getpid());
    exit(0);}
    printf("I am Process G my PID is %d\n",getpid());
    exit(0);
}