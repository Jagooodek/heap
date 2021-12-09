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
    
    while((*cmp)(newNode->value, newNode->parent->value)) {
        swap(newNode, newNode->parent);
        newNode = newNode->parent;
        if(newNode->parent == NULL)
            break;
    }
}

void pop() {
    struct heapNode *nodeToDelete = top;
    while(nodeToDelete->leftChild != NULL || nodeToDelete->rightChild != NULL) {
        if(nodeToDelete->leftChild != NULL && nodeToDelete->rightChild != NULL) {
            if((*cmp)(nodeToDelete->leftChild->value, nodeToDelete->rightChild->value)) {
                swap(nodeToDelete, nodeToDelete->leftChild);
                nodeToDelete = nodeToDelete->leftChild;
            } else {
                swap(nodeToDelete, nodeToDelete->rightChild);
                nodeToDelete = nodeToDelete->rightChild;
            }
        } else if(nodeToDelete->leftChild != NULL) {
            swap(nodeToDelete, nodeToDelete->leftChild);
            nodeToDelete = nodeToDelete->leftChild;
        } else if(nodeToDelete->rightChild != NULL) {
            swap(nodeToDelete, nodeToDelete->rightChild);
            nodeToDelete = nodeToDelete->rightChild;
        }

    }

    
    if(nodeToDelete->parent != NULL) {
        if(nodeToDelete->parent->leftChild == nodeToDelete) {
            nodeToDelete->parent->leftChild = NULL;
        } else {
            nodeToDelete->parent->rightChild = NULL;
        }
    }

    size--;
    if(size == 0)
        top = NULL;
    free(nodeToDelete);
}

