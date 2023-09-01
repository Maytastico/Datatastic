
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <malloc.h>

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

myQueue_t *QueueNew(size_t amount){
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
        *(p_Queue->write) = value;
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
