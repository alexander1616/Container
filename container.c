/*
Copyright Alexander Chan 2022
Simon Chan 2022

General purpose container creation
Maintain pointers of elements
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "container.h"

Container_t *container_alloc(int initSize){
    Container_t *p;
    p = malloc(sizeof(Container_t));
    if (p == 0){
        printf("No memory.\n");
        return p;
    };
    p->numElement = 0;
    p->pool = malloc(initSize * sizeof(void *));
    if (p->pool == 0){
        printf("No memory.\n");
        free(p);
        return 0;
    };
    p->maxNum = initSize;
    return p;
};

void container_free(Container_t *p){
    if (p == 0){
        return;
    }
    if (p->pool != 0){
        free(p->pool);
    };
    free(p);
};

int container_add(Container_t *p, void *ep){
    printf("Attempting to add...\n");
    if (p->numElement >= p->maxNum){
        printf("Attempting to expand size...\n");
        int dummysize;
        dummysize = p->maxNum << 1; // can adjust size here, double size
        void **vp = realloc(p->pool, dummysize * sizeof(void *)); //** b/c array of void ptr
        if (vp == 0){
            printf("No memory.\n");
            return -1;
        };
        p->pool = vp;
        p->maxNum = dummysize;
    }
    p->pool[p->numElement] = ep;
    p->numElement++;
    return 0;
}; // adding element pointer to container

int container_remove(Container_t *p, void *ep){
    printf("Attempting to remove...\n");
    int counter;
    for (counter = 0; counter < p->numElement; counter++){
        if (ep == p->pool[counter]){
            p->pool[counter] = 0;            
            int dummysize;
            dummysize = p->numElement - counter - 1;
            if (dummysize > 0 ){
            memmove(&(p->pool[counter]), &(p->pool[counter+1]), dummysize*sizeof(void*));
            };
            p->numElement--;
            return 0;
        };        
    };
    return -1;
};

int container_iterator(Container_t *p, void (*funcp)(void*)){
    //iterate pointers in my pool
    //return how many pointers it iterated
    int counter;
    for (counter = 0; counter < p->numElement; counter++){
        (*funcp)(p->pool[counter]);
    }
    (*funcp)(0); //signifying the end of process
    return counter;
};