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
    int key;
   if((key=ftok("Task31.c",'b'))==-1){
       printf("%s","error in Creation\n");
       return 0;
   }
    if((msgid=msgget(key,0644))==-1){
        perror("msgid");
        return 0;
    }
    int o;
    msgrcv(msgid,&msg,sizeof(msg),1,0);
    o=msg.msgtxt[0]-'0';
    strcpy(msg.msgtxt,"Ready");
    msgsnd(msgid,&msg,sizeof(msg),0);
    while(o<10){
        msgrcv(msgid,&msg,sizeof(msg),1,0);
        o*=2;
        msg.msgtxt[0]=o-'0';
        msgsnd(msgid,&msg,sizeof(msg),0);
    }
    msgrcv(msgid,&msg,sizeof(msg),1,0);
    msg.msgtxt[0]='-';
    msgsnd(msgid,&msg,sizeof(msg),0);
}