#ifndef HEAP_H_
#define HEAP_H_


void addElement(int key, int value);
int topValue();
int topKey();
void push();
int heapSize();
void setCmp(int (*)(int, int));


#endif