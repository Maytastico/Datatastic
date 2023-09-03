
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>

typedef void queueElement_t;

typedef struct {
    queueElement_t *bottom;
    queueElement_t *read;
    queueElement_t *write;
    bool full;
    bool empty;
    size_t size;
    size_t amount
} myQueue_t;

myQueue_t *QueueNew(size_t size, size_t amount){
    myQueue_t *pQueue = malloc(sizeof(myQueue_t));
    if(NULL==pQueue)return NULL;

    pQueue->bottom = malloc(amount * sizeof (queueElement_t));
    if(NULL == pQueue->bottom){
        free(pQueue);
        return NULL;
    }

    pQueue->read = pQueue->write = pQueue->bottom;
    pQueue->full = false; pQueue->empty = true;
    pQueue->amount = amount;
    pQueue->size = size;
    return pQueue;
}

int QueueDestroy(myQueue_t * p_Queue){
    if(NULL == p_Queue) return EXIT_FAILURE;

    free(p_Queue->bottom);
    p_Queue->bottom = NULL;

    free(p_Queue);
    return EXIT_SUCCESS;
}

bool IsQueueEmpty(myQueue_t * p_Queue){
    if(NULL!= p_Queue) return p_Queue->empty;
    else return true;
}

bool IsQueueFull(myQueue_t * p_Queue){
    if(NULL != p_Queue) return p_Queue->full;
    else return true;
}


int EnQueue(myQueue_t *p_Queue, queueElement_t *value) {
    int back = EXIT_FAILURE;

    if((NULL!=p_Queue)&&(p_Queue->full != true)){
        p_Queue->empty = false;
        memcpy(p_Queue->write, value, p_Queue->size );
        back = EXIT_SUCCESS;

        if(p_Queue->write == (p_Queue->bottom + p_Queue->amount-1)){
            p_Queue->write = p_Queue->bottom;
        }else{
            p_Queue->write++;
        }

        if(p_Queue->read == p_Queue->write) p_Queue->full = true;
    }
    return  back;
}

int DeQueue(myQueue_t *p_Queue, queueElement_t *value){

    if((NULL != p_Queue) && (p_Queue->empty != true)){
        p_Queue -> full = false;
        memcpy(value, p_Queue->read, p_Queue->size);

        if(p_Queue->read == (p_Queue->bottom + p_Queue->amount-1)){
            p_Queue->read = p_Queue->bottom;
        }else p_Queue->read++;

        if(p_Queue->read == p_Queue->write) p_Queue->empty = true;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

void enqueue_dequeue_demo();
void enqueue_dequeue_multiple_demo();

int main(){
    srand(time(NULL));
    enqueue_dequeue_demo();

    //enqueue_dequeue_multiple_demo();
}

void enqueue_dequeue_demo(){
    myQueue_t * test_queue = QueueNew(sizeof(int), 5);
    int zahl = 5;
    EnQueue(test_queue, &zahl);
    zahl = 10;
    EnQueue(test_queue, &zahl);
    zahl = 90;
    EnQueue(test_queue, &zahl);
    int dequeued = 0;
    DeQueue(test_queue, &dequeued);
    printf("%d\n", dequeued);
    DeQueue(test_queue, &dequeued);
    printf("%d\n", dequeued);
    DeQueue(test_queue, &dequeued);
    printf("%d\n", dequeued);
}

void enqueue_dequeue_multiple_demo(){
    myQueue_t *test_queue = QueueNew(sizeof(int), 30);
    for (int i = 0; i < 4; ++i) {
        int random_number = rand() % 20 + 1;
        EnQueue(test_queue, &random_number);
        int element = *((int *) (test_queue->read));
        printf("%d\n", element);
    }
    printf("--\n");
    for (int i = 0; i < 5; ++i) {
        int o_value = 0;
        DeQueue(test_queue, &o_value);
        printf("%d\n", o_value);
    }
}