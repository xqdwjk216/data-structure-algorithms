#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <stdio.h>

/*
    |----------6-----------|
    |----------5-----------|
    |----------4-----------|
    |----------3-----------|
    |----------2-----------|
    |----------1-----------| <- top
 */

struct Node
{
    int data;
    struct Node * next;
} _node;

struct Stack {
    /* 栈容量 */
    int size;
    /* 当前长度 */
    int length;
    /* 栈顶指针 */
    Node * top;
    int initStack(int size);
    int destroyStack();
    int clearStack();
    int push(Node * node);
    Node * pop();
    int isEmpty();
    Node * getTop();
    void traverse();
    static void demo();
    /* 匹配括号 */
    static void demoBracket(char * str);
};

int Stack::initStack(int size) {
    assert(size > 0);
    /* 分配连续空间并将top指向入口地址 */
    top = (Node *)malloc(sizeof(Node) * size);
    assert(top);
    top += sizeof(Node) * (size - 1);
    this->size = size;
    length = 0;
    return 1;
}

int Stack::destroyStack() {
    free(top);
    size = 0;
    length  = 0;
    return 1;
}

int Stack::push(Node * node) {
    top -= sizeof(Node);
    top->data = node->data;
    length++;
    return length;
}

Node * Stack::pop() {
    Node * tmp = top;
    top += sizeof(Node);
    length--;
    return tmp;
}

Node * Stack::getTop() {
    return top;
}

void Stack::traverse() {
    Node * cursor = top;
    while (length--) {
        printf("%d\n", cursor->data);
        cursor += sizeof(Node);
    }
}

int Stack::isEmpty() {
    return length == 0;
}

void Stack::demo() {
    printf("====栈====\n");
    printf("----push 5个元素----\n");

    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->initStack(10);

    Node * node = (Node *)malloc(sizeof(Node));
    Node * node2 = (Node *)malloc(sizeof(Node));
    Node * node3 = (Node *)malloc(sizeof(Node));

    node->data = 1;
    stack->push(node);

    node2->data = 2;
    stack->push(node2);

    node3->data = 3;
    stack->push(node3);

    stack->traverse();

    Node * tmp = stack->pop();
    printf("%d\n", tmp->data);
}

void Stack::demoBracket(char * str) {
    char * ptr = str;
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->initStack(30);
    while (*ptr != '\0') {
        if ( *ptr == '{' || *ptr == '[' || *ptr == '(' ) {
            Node *  node = (Node *)malloc(sizeof(Node));
            node->data = *ptr;
            stack->push(node);
        } else if ( *ptr == '}' || *ptr == ']' || *ptr == ')' ) {
            Node * top = stack->getTop();
            switch (*ptr) {
            case '}':
                if (top->data == '{') {
                    stack->pop();
                }
                break;
            case ']':
                if (top->data == '[') {
                    stack->pop();
                }
                break;
            case ')':
                if (top->data == '(') {
                    stack->pop();
                }
                break;
            }
        }
        ptr++;
    }
    printf("%s\n", stack->isEmpty() ? "match" : "not match");
}

#endif