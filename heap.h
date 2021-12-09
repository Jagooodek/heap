#ifndef HEAP_H_
#define HEAP_H_

void push(int key, int value);
void pop();
void setCmp(int (*)(int, int));
int topValue();
int topKey();
int heapSize();

#endif