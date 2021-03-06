/*4. Implement a simple client-server scenario using message queues
   * Client process send a string over message queue
   * Server process toggles the string and send back to client.*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// structure for message queue
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
   message.message_type = 1;
   printf("Write Message : ");
   fgets(message.msggg, 100, stdin);
   printf("Sent message is : %s \n", message.msggg);
   msgsnd(msg_id, &message, sizeof(message), 0); //send message
   msgrcv(msg_id, &message, sizeof(message), 1, 0); //used to receive message
   // display the message
   printf("Received Message is : %s \n", message.msggg);

   return 0;
}
