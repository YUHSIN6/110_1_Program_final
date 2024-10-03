#include "queue.h"

queue init_queue(){
    queue new_queue;
    new_queue.capacity = 10;
    new_queue.front = new_queue.capacity-1;
    new_queue.rear = new_queue.capacity-1;
    new_queue._queue = (point*)malloc(new_queue.capacity*sizeof(point));
    return new_queue;
}

point q_front(queue q){ 
    if (q_empty(q)){
        printf("> Error : Try to retrieve elements from empty queue.\n> Location : In queue.c, point q_front().\n");
        return make_point(0, 0);
    }
    return q._queue[(q.front+1)%q.capacity];
}

int q_empty(queue q){
    return q.front == q.rear;
}

int q_size(queue q){ 
    return (q.rear-q.front)+q.capacity*(q.rear<q.front);
}

void q_push(queue *q, point p){
    if((q->rear+1)%q->capacity == q->front){
        point* new_queue = (point*)malloc(q->capacity*2*sizeof(point));
        for (int i = (q->front+1)%q->capacity, j = 0; i != q->front; i = (i+1)%q->capacity) 
            new_queue[j++] = q->_queue[i];

        q->rear = q_size(*q)-1;
        q->capacity *= 2;
        q->front = q->capacity-1;

        free(q->_queue);
        q->_queue = new_queue;
    }
    q->rear = (q->rear+1)%q->capacity;
    q->_queue[q->rear] = p;
}

void q_pop(queue *q){
    q->front = (q->front+!q_empty(*q))%q->capacity;
}