#ifndef ADT_H
#define ADT_H

#include <assert.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node * next;
} _node;

struct LinkedList
{
    /* 数量 */
    int length;
    /* 头节点 */
    Node * head;
    /* 初始化 */
    int initList();
    /* 销毁 */
    int destroyList();
    /* 清空 */
    int clearList();
    /* 获取长度 */
    int getLength();
    /* 获取元素 */
    Node * getElem(int i);
    /* 插入 */
    int insertElem(int i, Node * node);
    /* 追加 */
    int appendElem(int i, Node * node);
    /* 删除 */
    int deleteElem(int i);
    /* 遍历 */
    int traverse();
    /*-----------demo---------------*/
    static void demo();
    /*-----------demo---------------*/
};

int LinkedList::getLength() {
    return length;
}

// 98 -> 99 -> 100
int LinkedList::deleteElem(int i) {
    assert(i >= 0 && i < length);
    if (length == 0) {
        return 0;
    }
    Node * node_i = getElem(i);
    assert(node_i);
    if ( i == 0) {
        /* 删除的是头节点,只需要将下一个节点更新为头节点 */
        if (node_i->next) {
            head = node_i->next;
        }
    } else {
        /* 取上一个节点 */
        Node * prev_node_i = getElem(i - 1);
        /* 将上一个节点的next设置为下一个节点 */
        prev_node_i->next = node_i->next;
    }
    delete node_i;
    length--;
    return length;
}

int LinkedList::initList() {
    length = 0;
    /* head初始化为空指针 */
    head = NULL;
    return 1;
}

Node * LinkedList::getElem(int i) {
    assert(i >= 0 && i <= length);
    Node * tmp = head;
    if (i == 0) {
        return head;
    }
    while (i--) {
        tmp = tmp->next;
    }
    return tmp;
}

int LinkedList::insertElem(int i, Node *node) {
    assert(node);
    node->next = NULL;
    /* 为空则直接添加 */
    if (length == 0) {
        head = node;
        assert(head);
    } else {
        /* 获取i节点 */
        Node * node_i = getElem(i);
        assert(node_i);
        /* node的next指向node_i */
        node->next = node_i;
        /* node_i前一个节点的next指向node */
        if ( i > 0) {
            Node * prev_node_i = getElem(i - 1);
            assert(prev_node_i);
            prev_node_i->next = node;
        } else {
            /* 当前节点变为头节点 */
            head = node;
        }
    }
    length++;
    return length;
}

int LinkedList::appendElem(int i, Node *node) {
    assert(node);
    node->next = NULL;
    /* 为空则直接添加 */
    if (length == 0) {
        head = node;
        assert(head);
    } else {
        /* 获取i节点 */
        Node * node_i = getElem(i);
        assert(node_i);
        /* 将node_i的next指向node */
        node->next = node_i->next;
        node_i->next = node;
    }
    length++;
    return length;
}

int LinkedList::traverse() {
    if (length == 0) {
        return 0;
    }
    Node * tmp = head;
    while (tmp) {
        printf("%d", tmp->data);
        if (!tmp->next) {
            break;
        }
        printf(",");
        tmp = tmp->next;
    }
    printf("\n");
    return 1;
}

void LinkedList::demo() {
    printf("====单链表====\n");
    printf("----添加5个元素----\n");
    LinkedList * list = (LinkedList *)malloc(sizeof(LinkedList));
    list->initList();
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = 100;
    list->appendElem(0, node);

    Node * node2 = (Node *)malloc(sizeof(Node));
    node2->data = 101;
    list->appendElem(0, node2);

    Node * node3 = (Node *)malloc(sizeof(Node));
    node3->data = 102;
    list->appendElem(1, node3);

    list->traverse();

    Node * node4 = (Node *)malloc(sizeof(Node));
    node4->data = 99;
    list->insertElem(0, node4);

    Node * node5 = (Node *)malloc(sizeof(Node));
    node5->data = 98;
    list->insertElem(0, node5);

    printf("----输出----\n");
    list->traverse();

    printf("----删除元素----\n");
    list->deleteElem(0);
    printf("----输出----\n");
    list->traverse();

    printf("----删除元素----\n");
    list->deleteElem(1);
    printf("----输出----\n");
    list->traverse();
}

#endif