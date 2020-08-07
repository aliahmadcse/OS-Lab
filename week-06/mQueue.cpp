#include <bits/stdc++.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
};

int main()
{
    key_t key;
    int msgid;

    key = ftok("hello world", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    int n = fork();

    if (n < 0)
    {
        cout << "Process Creation Failed!\n";
    }
    else if (n == 0)
    {
        mesg_buffer receivedMessage;

        msgrcv(msgid, &receivedMessage, sizeof(receivedMessage), 1, 0);


        //displaying the date 
        cout << "Date Received is : " <<  receivedMessage.mesg_text << endl;

        //destroying the message queue 
        msgctl(msgid, IPC_RMID, NULL);
    }
    else
    {
        mesg_buffer sentMessage;
        sentMessage.mesg_type = 1;
        //sending current date and time from parent process
        time_t now = time(0);

        string date = ctime(&now);
        strcpy(sentMessage.mesg_text, date.c_str());

        msgsnd(msgid, &sentMessage, sizeof(sentMessage), 0);

    }


    return 0;
}
