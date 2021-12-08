#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct dataStruct {
    char * firstName;
    char * lastName;
    int age;
};

int Cmp(int a, int b) {
    return a < b;
}

int main() {
    setCmp(&Cmp);
    int n;
    printf(u8"Podaj długość listy\n");
    scanf("%d", n);
    
    struct dataStruct  *data = malloc
    
    return 0;
}
