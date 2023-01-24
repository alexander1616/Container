#ifndef container_h
#define container_h 1
typedef struct {
    int numElement; //number of elements in struct
    void **pool; //datapointer for each element
    int maxNum; //upper bound of elements in container
} Container_t;

#ifdef __cplusplus //if c++ we need to extern
extern "C" {
#endif
    Container_t* container_alloc(int initSize);
    void container_free(Container_t*);
    int container_add(Container_t*, void *ep); //adding element pointer to container
    int container_remove(Container_t*, void *ep);
    int container_iterator(Container_t*, void (*)(void*));
#ifdef __cplusplus //removes the closing bracket for c compiler
};
#endif
#endif // container_h
