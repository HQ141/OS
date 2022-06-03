#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t st=getpid();
    pid_t a[4];
    int i;
    for(i=0;i<4;i++){
        a[i]=fork();
        if(a[i]==0)
        break;
        if(a<0)
        exit(0);
    }
    if(getpid()!=st){
            while((wait(NULL)>0))
                i=i;
            printf("Process %d ,Pid= %d\n",i,getpid());
            exit(0);           
        
    }
    while((wait(NULL)>0))
    i=1;
    printf("parent Ending\n");

}