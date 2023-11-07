#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int priority;
    int burstTime;
};

struct Queue {
    struct Process** processes;
    int front, rear, size;
};

struct Process* createProcess(int id, int priority, int burstTime) {
    struct Process* process = (struct Process*)malloc(sizeof(struct Process));
    process->id = id;
    process->priority = priority;
    process->burstTime = burstTime;
    return process;
}

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->processes = (struct Process**)malloc(sizeof(struct Process*) * size);
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

void enqueue(struct Queue* queue, struct Process* process) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->processes[queue->rear] = process;
    }
}

struct Process* dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Process* process = queue->processes[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return process;
}

int main() {
    struct Queue* queue1 = createQueue(100);
    struct Queue* queue2 = createQueue(100);
    struct Queue* queue3 = createQueue(100);

    struct Process* process1 = createProcess(1, 1, 10);
    struct Process* process2 = createProcess(2, 2, 15);
    struct Process* process3 = createProcess(3, 3, 8);

    enqueue(queue1, process1);
    enqueue(queue2, process2);
    enqueue(queue3, process3);

    struct Process* currProcess;

    // FCFS
    currProcess = dequeue(queue1);
    printf("Processing process %d with FCFS policy\n", currProcess->id);

    // Priority scheduling
    currProcess = dequeue(queue2);
    printf("Processing process %d with Priority Scheduling policy\n", currProcess->id);

    // Round-robin scheduling 
    currProcess = dequeue(queue3);
    printf("Processing process %d with Round Robin policy\n", currProcess->id);

    free(queue1->processes);
    free(queue1);
    free(queue2->processes);
    free(queue2);
    free(queue3->processes);
    free(queue3);
    free(process1);
    free(process2);
    free(process3);

    return 0;
}

