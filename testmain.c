#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "container.h"

//testing my functions
typedef struct{
    char name[20];
    int count;
    int age;
} Testelement_t;

Testelement_t toby = {
    .name="toby",
    .count=1,
    .age=5
};

Testelement_t godzilla = {
    .name="godzilla",
    .count=2,
    .age=10
};

Testelement_t brownie = {
    .name="brownie",
    .count=3,
    .age=15
};

void printElement(Testelement_t* p){
    if (p == 0){
        printf("End\n"); //hand in hand with container.c iterating end condition
    } else {
    printf("Name:%s, Count:%d, Age%d\n", p->name, p->count, p->age);
    }
};

void testfunc(){
    Container_t* p;
    int returncode;
    p = container_alloc(2);
    printf("Testing allocation of new container: %p\n", p);
    container_iterator(p, (void(*)(void *))printElement);
    Testelement_t *x = malloc(sizeof(Testelement_t));
    strcpy(x -> name, "simon");
    x -> age = 26;
    x -> count = 4;
    container_add(p, x);
    container_add(p, &toby);
    container_add(p, &godzilla);
    container_add(p, &brownie);
    container_iterator(p, (void(*)(void *))printElement);
    container_remove(p, &godzilla);
    container_iterator(p, (void(*)(void *))printElement);
    container_remove(p, &brownie);
    container_iterator(p, (void(*)(void *))printElement);
    returncode = container_remove(p, &toby);
    printf("Return code: %d\n", returncode);
    container_iterator(p, (void(*)(void *))printElement);
    returncode = container_remove(p, &toby);
    printf("Return code: %d\n", returncode);
    container_iterator(p, (void(*)(void *))printElement);
    container_free(p);
    printf("Container is deleted: %p\n", p);
};

int main(int ac, char * av[]){
    testfunc();
    return 0;
};