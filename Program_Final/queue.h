#include "shared.h"

typedef struct Queue{
    // The fornt index
    int front;
    // The rear index
    int rear;
    // The capacity of the queue
    int capacity;
    // The array to store data of the stack
    point* _queue;
} queue;

// Initialize the value of the queue
queue init_queue();
// Return the front element of the queue
point q_front(queue q);
// Return the size of the queue
int q_size(queue q);
// Check if the queue is empty
int q_empty(queue q);
// Insert a new element at the rear of the queue
void q_push(queue *q, point p);
// Pop out the front element in the queue
void q_pop(queue *q);