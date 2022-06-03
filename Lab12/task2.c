#include <stdio.h> //needs for perror
#include <signal.h> //signal.h
#include<wait.h>
#include<unistd.h>

void handler(int signum){
if(signum == SIGKILL)
printf("\nCant kill this\n");
if(signum == SIGSTOP)
printf("\nCant stop this\n");


}
int main(){
struct sigaction sa; 
sa.sa_handler = handler; 
while(1){
printf("/");
}
return 0;
}