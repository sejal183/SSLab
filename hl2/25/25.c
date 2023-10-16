/*
 * ============================================================================
 Name : 25.c
 Author : Sejal Khandelwal
 Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
 Date: 10th OCT, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key = ftok("/tmp", 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    int msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        return 1;
    }

    // Structure for message queue attributes.
    struct msqid_ds msgAttrib;

    // Get the attributes of the message queue.
    if (msgctl(msqid, IPC_STAT, &msgAttrib) == -1) {
        perror("msgctl");
        return 1;
    }

    // Print the message queue attributes.
    printf("a. Access Permissions: %#o\n", msgAttrib.msg_perm.mode);
    printf("b. UID: %d\n", msgAttrib.msg_perm.uid);
    printf("   GID: %d\n", msgAttrib.msg_perm.gid);

    printf("c. Time of Last Message Sent: %s", ctime(&msgAttrib.msg_stime));
    printf("   Time of Last Message Received: %s", ctime(&msgAttrib.msg_rtime));
    printf("d. Time of Last Change: %s", ctime(&msgAttrib.msg_ctime));

    printf("e. Size of the Queue: %lu bytes\n", msgAttrib.msg_qbytes);
    printf("f. Number of Messages in the Queue: %lu\n", msgAttrib.msg_qnum);
    printf("g. Maximum Number of Bytes Allowed: %lu bytes\n", msgAttrib.msg_qbytes);
    printf("h. PID of msgsnd: %d\n", msgAttrib.msg_lspid);
    printf("   PID of msgrcv: %d\n", msgAttrib.msg_lrpid);

    return 0;
}

