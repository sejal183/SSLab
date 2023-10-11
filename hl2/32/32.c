/*
 * ============================================================================
 Name : 32.c
 Author : Sejal Khandelwal
 Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
 Date: 10th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <unistd.h>

#define NUM_TICKETS 10

sem_t semaphore;  // Semaphore for controlling access to the critical section
int ticket_counter = 0;

void *generate_ticket(void *arg) {
    int ticket_number;

    for (int i = 0; i < NUM_TICKETS; i++) {
        sem_wait(&semaphore); // Wait for access to the critical section

        ticket_number = ticket_counter++;
        printf("Ticket %d generated by thread %ld\n", ticket_number, (long)arg);

        sem_post(&semaphore); // Release the semaphore, allowing other threads to enter
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_TICKETS];
    int i;

    // Initialize the semaphore with an initial value of 1
    if (sem_init(&semaphore, 0, 1) != 0) {
        perror("sem_init");
        exit(EXIT_FAILURE);
    }

    // Create multiple threads to generate tickets
    for (i = 0; i < NUM_TICKETS; i++) {
        if (pthread_create(&threads[i], NULL, generate_ticket, (void *)(intptr_t)i) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_TICKETS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    // Destroy the semaphore when done
    sem_destroy(&semaphore);

    return 0;
}


