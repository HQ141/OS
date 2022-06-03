#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf{
    long mtype;
    char msgtxt[200];
};
int main(){
    struct msgbuf msg;
    int msgid;
    key_t key;
   if((key=ftok("Task31.c",'b'))==-1){
       printf("%s","error in Creation\n");
       return 0;
   }
   if((msgid=msgget(key,0644|IPC_CREAT))==-1){
       printf("%s","error in Creation\n");
       return 0;
   }
   int a;
   msg.msgtxt[0]=a+'0';
   if((msgsnd(msgid,&msg,sizeof(msg),0)==-1)){
       perror("Error");
       return 0;
   }
   if((msgrcv(msgid,&msg,sizeof(msg),1,0))==-1){
       perror("Error");
       return 0;
   }
   if(strcmp(msg.msgtxt,"Ready")==0){
       printf("%d",a);
    
   for(;;){
   msg.msgtxt[0]='*';
   if((msgsnd(msgid,&msg,sizeof(msg),0)==-1)){
       perror("Error");
       return 0;
   }
   if((msgrcv(msgid,&msg,sizeof(msg),1,0))==-1){
       perror("Error");
       return 0;
   }
   if(msg.msgtxt[0]=='-')
    return 0;
   printf("%s",msg.msgtxt);
   }
   }

   else
   return 0;
}

