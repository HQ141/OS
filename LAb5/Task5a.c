#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t a[2];
    int my=1;
    int i;
    for(i=0;i<2;i++){
        a[i]=fork();
        if(a[i]==0)
        break;
    }
    if(i==0){
        printf("I am Process 5 my PID is %d\n",getpid());
        exit(0);
    }
    if(i==1){
        int aa=fork();
        if(aa){
        wait(NULL);
        printf("I am Process 3 my PID is %d\n",getpid());
        exit(0);
        }
        else{
            printf("I am Process 4 my PID is %d\n",getpid());
            exit(0);
        }
    }
    else{
        while((wait(NULL)>0));
        printf("I am Process 1 my PID is %d\n",getpid());
        exit(0);
    }
    

}