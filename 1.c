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
    int n, index;
    printf(u8"Podaj długość listy.\n");
    scanf("%d", &n);
    
    struct dataStruct  *data = malloc(sizeof(struct dataStruct) * n);

    printf(u8"Podaj listę.\n");

    for(int i = 0; i < n; i++) {
        scanf("%s %s %d ", data[i].firstName, data[i].lastName, &data[i].age);
        push(i, data[i].age);
    }

    for(int i = 0; i < n; i++) {
        index = topKey();
        pop();
        printf("%s %s %d\n", data[index].firstName, data[index].lastName, data[index].age);
    }
    
    return 0;
}
