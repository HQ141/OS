#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
    char buffer [8];
    int fd,retv;
    fflush(stdin);
    int i,a=90;
    for(i=0;i<2&&a!=0;i++)
        a=fork();
    fd=open("myfifo",O_RDONLY);
    read(fd,buffer,sizeof(buffer));
    close(fd);
    printf("%s\n",buffer);
    return 0;
}