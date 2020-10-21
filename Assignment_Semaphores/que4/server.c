#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// Define message queue structure
struct msg_buffer 
{
   long message_type;
   char msggg[100];
} message;

int main() 
{
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65); //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT); //create message queue and return id
   msgrcv(msg_id, &message, sizeof(message), 1, 0); //used to receive message
   // display the message
   printf("Received Message is : %s \n", message.msggg);
    printf("Write Message : ");
   fgets(message.msggg, 100, stdin);
   /*switch(message.msq)
   {
   case 'e':printf("Write Message : ");
   msgctl(msg_id, IPC_RMID, NULL);
   break;
   default:}*/
  
   msgsnd(msg_id, &message, sizeof(message), 0); 
   
   printf("Sent message is : %s \n", message.msggg);
   return 0;
}
