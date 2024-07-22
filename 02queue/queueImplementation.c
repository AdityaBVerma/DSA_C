#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue{
    int* arr;
    int front;
    int rear;
    int capacity;
}Queue;

struct Queue* createQueue(int capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = -1;
	queue->rear = -1;
	queue->arr = (int*)malloc(queue->capacity*sizeof(int));
	return queue;
}

int isFull(struct Queue* queue){
	return (queue->arr[queue->rear] == (queue->capacity)-1);
}

int isEmpty(struct Queue* queue){
	return (queue->front==-1 && queue->rear==-1);
}

void enqueue(struct Queue* queue, int value){
	if(isFull(queue)){
		printf("queue is full \n");
		exit(1);
	}
	if(queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	}
	queue->arr[queue->rear++] = value;
}

int dequeue(struct Queue* queue){
	if(isEmpty(queue)){
		printf("queue is empty \n");
		exit(1);
	}
	int firstElement = queue->arr[queue->front];
	queue->front++;
	return firstElement;
}

int peek(struct Queue* queue){
	return (queue->arr[queue->front]);
}

void display(struct Queue* queue){
	int i = 0;
	for(i = queue->front; i < queue->rear; i++){
		printf("%d ",queue->arr[i]);
	}
}

int main(){
	
    struct Queue* queue = createQueue(4);

    enqueue(queue, 6);
    enqueue(queue, 4);
    enqueue(queue, 9);
    enqueue(queue, 2);
    enqueue(queue, 5);

    printf("\nQueue: \n");
    display(queue);

    int dequeuedElement = dequeue(queue);
    printf("\nDequeued: %d\n", dequeuedElement);

    printf("\nQueue: \n");
    display(queue);

    int empty = isEmpty(queue);
    printf("\nIs the queue empty? %d\n", empty);

	return 0;
}