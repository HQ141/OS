#include <stdio.h> //needs for perror
#include <signal.h> //signal.h
#include<wait.h>
#include<unistd.h>

void sig_handler(int signo){
if (signo == SIGUSR1)
printf("received SIGUSR1\n");
else if (signo == SIGKILL)
printf("received SIGKILL\n");
else if (signo == SIGSTOP)
printf("received SIGSTOP\n");
}
int main(){
struct sigaction sa; //creating sa, which will be called in sigaction function with the control signal variable
sa.sa_handler = sig_handler; //this is declaring which handler is used if control signal is passed to sa;
while(1)
sleep(1);
if(sigaction(SIGINT, &sa, NULL) == -1)
perror("S1GACTION");

return 0;
}