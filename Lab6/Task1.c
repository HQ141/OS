#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>
int fd[2];
int main(){
    if(pipe(fd)==-1){
        printf("Error in making Pipe\n");
        return 1;
    }
    if(fork()==0){
        close(fd[1]);
        int x;
        if(read(fd[0],&x,sizeof(int))==-1){
            printf("Error in reading\n");
            return 2;
        }
        printf("Parent recieved %d",x);
        close(fd[0]);
        wait(NULL);
        return 0;
    }
    else{
        close(fd[0]);
        int x;
        printf("Input Number\n");
        scanf("%d",&x);
        if(write(fd[1],&x,sizeof(int))==-1){
            printf("Error in writing");
        }
        return 0;
    }
}