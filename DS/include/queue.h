#ifndef QUEUE_H
#define QUEUE_H

#include <assert.h>
#include <stdio.h>

/*
    10 -> 9 -> 8 -> 7 ->6 -> 5 -> 4 -> 3 -> 2 -> 1
tail x                                           x head
            ↓
    |----------6-----------| <- top
    |----------5-----------| <- head
    |----------4-----------|
    |----------3-----------|
    |----------2-----------| <- head
    |----------1-----------| <- tail
            ↓
 */

struct Node
{
    int data;
    struct Node * next;
} _node;

struct Queue {
    /* 栈容量 */
    int size;
    /* top */
    Node * top;
    Node * head;
    Node * tail;
    int initQueue(int size);
    int destroyQueue();
    int clearQueue();
    /* 入队列 */
    void enqueue(Node *node);
    /* 出队列 */
    Node * dequeue();
    void traverse();
    static void demo();
};

int Queue::initQueue(int size) {
    assert(size > 0);
    /* 分配连续空间并将top指向入口地址 */
    top = (Node *)malloc(sizeof(Node) * size);
    assert(top);
    tail = top + sizeof(Node) * (size - 1);
    head = tail;
    this->size = size;
    return 1;
}

void Queue::enqueue(Node * node) {
    if (head <= top) {
        /* 队列满了,将tail指向head */
        printf("queue is full\n");
        /* TODO 环形队列实现 */
    }
    head->data = node->data;
    head -= sizeof(Node);
}

Node * Queue::dequeue() {
    Node * node = tail;
    tail -= sizeof(Node);
    return node;
}

void Queue::traverse() {
    Node * cursor = head;
    do {
        printf("%d,", cursor->data);
        cursor += sizeof(Node);
    } while (cursor <= tail);
    printf("\n");
}


void Queue::demo()
{
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->initQueue(10);
    for (int i = 1; i <= 10; i++) {
        Node * node = (Node *)malloc(sizeof(Node));
        node->data = i;
        queue->enqueue(node);
    }

    queue->traverse();
    
    Node * tmp = queue->dequeue();
    printf("%d\n", tmp->data);
    queue->traverse();
    
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->traverse();

    tmp->data = 11;
    queue->enqueue(tmp);
    queue->traverse();
}

#endif