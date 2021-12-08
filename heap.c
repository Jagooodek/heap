#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "heap.h"

struct heapNode{
    int key;
    int value;
    struct heapNode *leftChild;
    struct heapNode *rightChild;
    struct heapNode *parent;

}heapNode;

struct heapNode *top = NULL;
int size = 0;



int defaultCmp(int a, int b) {
    return a > b;
}

int (*cmp)(int, int) = &defaultCmp;

void setCmp(int(*compareFunction)(int, int)) {
    cmp = compareFunction;
}

int topKey() {
    return top->key;
}

int topValue() {
    return top->value;
}

int heapSize() {
    return size;
}

void swap(struct heapNode *a, struct heapNode *b) {
    int tmp;
    tmp = a->key;
    a->key = b->key;
    b->key = tmp;

    tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}

void push(int key, int value) {
    struct heapNode* newNode = malloc(sizeof(heapNode));
    newNode->key = key;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    int where = size+1;
    size++;
    if(top == NULL) {
        top = newNode;
        return;
    }
    struct heapNode *tmpHeapNode = top;
    
    while(where >=4){
        if(where%2) {
            tmpHeapNode = tmpHeapNode->leftChild;
        } else {
            tmpHeapNode = tmpHeapNode->rightChild;
        }
        where /= 2;
    }
    if(where%2 == 0)
        tmpHeapNode->leftChild = newNode;
    else
        tmpHeapNode->rightChild = newNode;
    newNode->parent = tmpHeapNode;
    
    struct heapNode *a = newNode->parent;
    struct heapNode *b = newNode;

    while((*cmp)(b->value, a->value)) {
        swap(a, b);
        if(a->parent == NULL)
            break;
        b = a;
        a = a->parent;
    }
}

void pop() {
    struct heapNode *tmp = top;
    while(tmp->leftChild != NULL || tmp->rightChild != NULL) {
        if(tmp->leftChild != NULL && tmp->rightChild != NULL) {
            if((*cmp)(tmp->leftChild->value, tmp->rightChild->value)) {
                swap(tmp, tmp->leftChild);
                tmp = tmp->leftChild;
            } else {
                swap(tmp, tmp->rightChild);
                tmp = tmp->rightChild;
            }
        }else if(tmp->leftChild != NULL) {
            swap(tmp, tmp->leftChild);
            tmp = tmp->leftChild;
        }else if(tmp->rightChild != NULL) {
            swap(tmp, tmp->rightChild);
            tmp = tmp->rightChild;
        }

    }

    
    if(tmp->parent != NULL) {
        if(tmp->parent->leftChild == tmp) {
            tmp->parent->leftChild = NULL;
        } else {
            tmp->parent->rightChild = NULL;
        }
    }

    size--;
    free(tmp);
}

