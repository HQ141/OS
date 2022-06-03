#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<sys/wait.h>
int main(){
    int fd,retval;
    char buffer[8]="KAIZUKO";
    fflush(stdin);
    retval=mkfifo("myfifo",0666);
    for(int i=0;i<3;i++){
    fd=open("myfifo",O_WRONLY);
    buffer[7]=i+'0';
    write(fd,buffer,sizeof(buffer));
    close(fd);
    }
    return 0;
}