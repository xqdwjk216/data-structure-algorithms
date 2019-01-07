#ifndef QUEUE_H
#define QUEUE_H

#include <assert.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node * lchild;
    struct Node * parent;
    struct Node * rchild;
} _node;

struct Btree {
    Node * new_node(int i);
    void initBtree(int i);
    void add_node(Node * node);
    /* 中序 */
    void inorder_traverse(Node * proot = NULL);
    void preorder_traverse(Node * proot = NULL);
    void postorder_traverse(Node * proot = NULL);
    static void demo();
    Node * root;
};

Node * Btree::new_node(int i) {
    Node * node = (Node *)(malloc(sizeof(Node)));
    node->lchild = node->rchild = node->parent = NULL;
    node->data = i;
    return node;
}

void Btree::initBtree(int i) {
    root = (Node *)(malloc(sizeof(Node)));
    root->lchild = root->rchild = root->parent = NULL;
    root->data = i;
}

void Btree::add_node(Node * node) {
    if (root == NULL) {
        return;
    }

    Node * tmp = root;
    while (tmp != NULL) {
        if (node->data < tmp->data) {
            /* 添加到左边 */
            if (tmp->lchild == NULL) {
                /* 左边为空直接添加 */
                tmp->lchild = node;
                node->parent = tmp;
                return;
            } else {
                /* 继续去左节点找 */
                tmp = tmp->lchild;
            }
        } else if (node->data == tmp->data) {
            return;
        } else {
            /* 添加到右边 */
            if (tmp->rchild == NULL) {
                /* 左边为空直接添加 */
                tmp->rchild = node;
                node->parent = tmp;
                return;
            } else {
                /* 继续去右节点找 */
                tmp = tmp->rchild;
            }
        }
    }
}

/**
 * 中序 左 -> 根 -> 右
 */
void Btree::inorder_traverse(Node * proot) {
    if (proot == NULL) {
        proot = root;
    }

    Node * tmp = proot;
    if (tmp != NULL) {
        if (tmp->lchild != NULL) {
            inorder_traverse(tmp->lchild);
        }
        printf("%d,", tmp->data);
        if (tmp->rchild != NULL) {
            inorder_traverse(tmp->rchild);
        }
    }
}

/**
 * 前序 根 -> 左 -> 右
 */
void Btree::preorder_traverse(Node * proot) {
    if (proot == NULL) {
        proot = root;
    }

    Node * tmp = proot;
    if (tmp != NULL) {
        printf("%d,", tmp->data);
        if (tmp->lchild != NULL) {
            preorder_traverse(tmp->lchild);
        }
        if (tmp->rchild != NULL) {
            preorder_traverse(tmp->rchild);
        }
    }
}

/**
 * 后序 左 -> 右 -> 根
 */
void Btree::postorder_traverse(Node * proot) {
    if (proot == NULL) {
        proot = root;
    }

    Node * tmp = proot;
    if (tmp != NULL) {
        if (tmp->lchild != NULL) {
            postorder_traverse(tmp->lchild);
        }
        if (tmp->rchild != NULL) {
            postorder_traverse(tmp->rchild);
        }
        printf("%d,", tmp->data);
    }
}

void Btree::demo() {
    int arr[] = {50, 40, 60, 80, 100, 200, 260};
    Btree * btree = (Btree *)(malloc(sizeof(Btree)));
    btree->initBtree(90);
    int length = sizeof(arr) / sizeof(int);
    for (int i = 0; i < length; i++) {
        Node * node = btree->new_node(arr[i]);
        btree->add_node(node);
    }
    btree->inorder_traverse();
    printf("\n");
    btree->preorder_traverse();
    printf("\n");
    btree->postorder_traverse();
    printf("\n");
}

#endif